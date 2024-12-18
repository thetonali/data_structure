#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 20
#define MAX_LINE 1024

//关键字结构体中的存放位置的链表
typedef struct lineNode {
    int line;
    struct lineNode *next;
} LineNode;

//关键字
typedef struct {
    char word[MAX];              //名字
    int count;                   //关键字出现次数
    LineNode *lines;             //链表——存放出现的位置在哪一行(其实数组也行但大小需要预先确定)
} Keyword;


void addLine(LineNode **head, int line) {
    LineNode *cur = *head;
    LineNode *newNode = (LineNode *)malloc(sizeof(LineNode));
    newNode->line = line;
    newNode->next = NULL;

    if (*head == NULL) { //链表为空，直接将新节点设为头节点
        *head = newNode;
        return;
    }

    while (cur->next != NULL) {
        if (cur->line == line) //行号已存在
            return;
        cur = cur->next;
    }

    cur->next = newNode; // 将新节点连接到链表的尾部
}


void freeLines(LineNode *head) {
    while (head != NULL) {
        LineNode *temp = head;
        head = head->next;
        free(temp);
    }
}

int binary(Keyword keywords[], int low, int high, char* word) {
    while (low <= high) {
        int mid = (low + high) / 2;
        int cmp = strcmp(keywords[mid].word, word);
        if (cmp == 0)
            return mid;
        else if (cmp < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

void initKeywords(char *filename, Keyword keywords[]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("文件打开失败!");
        exit;
    }

    for(int i=0;i<32;i++){
        if(fscanf(file,"%s",keywords[i].word)){
            keywords[i].count=0;
            keywords[i].lines=NULL;
        }
    }
    fclose(file);
}

void processLine(char *filename, Keyword keywords[], int keywordCount) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("文件打开失败!");
        exit;
    }

    char line[MAX_LINE];
    int lineNum = 1;

    //fgets如果成功读取一行，返回line指针
    while (fgets(line, MAX_LINE, file)) {
        //strtok将字符串按指定分割符集分割，返回指向第一个Word的指针(第一个分割出来的单词)
        //找不到或遍历完，返回null
        char *word = strtok(line, " \t\r\n.,;!?\"'()[]{}<> ");

        while (word) {
            //当前字符word[i]为空字符时退出
            for (int i = 0; word[i]; i++)
                word[i] = tolower(word[i]);

            int index = binary(keywords, 0, keywordCount-1, word);
            if (index != -1) {
                keywords[index].count++;
                //需要修改keywords[index].lines本身的内容，传入其地址，使函数能在其本身进行操作
                addLine(&keywords[index].lines, lineNum);
            }
            word = strtok(NULL, " \t\r\n.,;!?\"'()[]{}<>");
        }
        lineNum++;
    }
    fclose(file);
}

void writeOutput(char *filename, Keyword keywords[], int keywordCount) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("文件打开失败!");
        exit;
    }

    fprintf(file,"word\t\ttimes\t\tposition\n");
    for (int i = 0; i < keywordCount; i++) {
        fprintf(file, "%-12s", keywords[i].word);
        fprintf(file, "%-13d", keywords[i].count);
        
        LineNode *lineNode = keywords[i].lines;
        while (lineNode) {
            fprintf(file, "%d ", lineNode->line);
            lineNode = lineNode->next;
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

void freeMemory(Keyword keywords[], int keywordCount) {
    for (int i = 0; i < keywordCount; i++) {
        freeLines(keywords[i].lines);
    }
}

int main() {
    Keyword keywords[32]; //关键字数组/结构体数组

    initKeywords("keywords.txt", keywords);
    processLine("countKeywords.c", keywords, 32);
    writeOutput("output.txt", keywords, 32);
    freeMemory(keywords,32);

    return 0;
}
