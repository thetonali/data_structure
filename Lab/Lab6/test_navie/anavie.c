#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEYWORDS 32
#define MAX_WORD_LENGTH 20
#define MAX_LINE_LENGTH 1024

typedef struct LineNode {
    int line;
    struct LineNode *next;
} LineNode;

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
    LineNode *lines;
} Keyword;

void addLine(LineNode **head, int line) {
    LineNode *current = *head;
    while (current != NULL) {
        if (current->line == line) return; // Line already exists
        current = current->next;
    }
    LineNode *newNode = (LineNode *)malloc(sizeof(LineNode));
    newNode->line = line;
    newNode->next = *head;
    *head = newNode;
}

void freeLines(LineNode *head) {
    while (head != NULL) {
        LineNode *temp = head;
        head = head->next;
        free(temp);
    }
}

int compareKeywords(const void *a, const void *b) {
    return strcmp(((Keyword *)a)->word, ((Keyword *)b)->word);
}

int binarySearch(Keyword keywords[], int low, int high, const char *word) {
    while (low <= high) {
        int mid = (low + high) / 2;
        int cmp = strcmp(keywords[mid].word, word);
        if (cmp == 0) return mid;
        else if (cmp < 0) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

void loadKeywords(const char *filename, Keyword keywords[], int *count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open keyword file");
        exit(EXIT_FAILURE);
    }

    *count = 0;
    while (*count < MAX_KEYWORDS && fscanf(file, "%s", keywords[*count].word) == 1) {
        keywords[*count].count = 0;
        keywords[*count].lines = NULL;
        (*count)++;
    }

    fclose(file);
    qsort(keywords, *count, sizeof(Keyword), compareKeywords);
}

void processFile(const char *filename, Keyword keywords[], int keywordCount) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open text file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int lineNumber = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        lineNumber++;
        char *token = strtok(line, " \t\r\n.,;!?\"'()[]{}<>");

        while (token) {
            for (int i = 0; token[i]; i++) token[i] = tolower(token[i]);

            int index = binarySearch(keywords, 0, keywordCount - 1, token);
            if (index != -1) {
                keywords[index].count++;
                addLine(&keywords[index].lines, lineNumber);
            }

            token = strtok(NULL, " \t\r\n.,;!?\"'()[]{}<>");
        }
    }

    fclose(file);
}

void writeOutput(const char *filename, Keyword keywords[], int keywordCount) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open output file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < keywordCount; i++) {
        fprintf(file, "Keyword: %s\n", keywords[i].word);
        fprintf(file, "Count: %d\n", keywords[i].count);
        fprintf(file, "Lines: ");
        
        LineNode *lineNode = keywords[i].lines;
        while (lineNode) {
            fprintf(file, "%d ", lineNode->line);
            lineNode = lineNode->next;
        }
        fprintf(file, "\n\n");
    }

    fclose(file);
}

void freeMemory(Keyword keywords[], int keywordCount) {
    for (int i = 0; i < keywordCount; i++) {
        freeLines(keywords[i].lines);
    }
}

int main() {
    Keyword keywords[MAX_KEYWORDS];
    int keywordCount;

    loadKeywords("keywords_text.txt", keywords, &keywordCount);
    processFile("novel_test.txt", keywords, keywordCount);
    writeOutput("output_test.txt", keywords, keywordCount);
    freeMemory(keywords, keywordCount);

    printf("Keyword statistics written to output.txt\n");
    return 0;
}
