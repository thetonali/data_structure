#include <stdio.h>
#include <stdlib.h>

//双链表的节点结构
typedef struct line{
    struct line*prior;
    int data;
    struct line* next;
}line;

//创建双链表
line* initLine(line*head){
    head=(line*)malloc(sizeof(line));//创建第一个结点
    head->next=NULL;
    head->prior=NULL;
    head->data=1;

    line* tail=head;
    for(int i=2;i<=6;i++){
        //创建并初始化一个新结点
        line* newNode=(line*)malloc(sizeof(line));
        newNode->prior=NULL;
        newNode->next=NULL;
        newNode->data=i;

        tail->next=newNode;
        newNode->prior=tail;
        tail=tail->next;
    }
    return head;
}

void disply(line*list){
    line*tmp=list;
    while(tmp){
        if(tmp->next==NULL)
            printf("%d\n",tmp->data);
        else
            printf("%d<->",tmp->data);
        tmp=tmp->next;
    }
}

// int main(){
//     line*head=NULL; //创建一个头指针，初始化需要头指针
//     head=initLine(head);
//     disply(head);
//     return 0;
// }


