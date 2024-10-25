#include <stdio.h>
#include <stdlib.h>

typedef struct lnode{
    int data;
    struct lnode*next;
}Lnode,*LinkList;

int main(){
    int n;
    scanf("%d",&n);

    //头节点
    Lnode*p=(Lnode*)malloc(sizeof(Lnode));
    p->next=NULL;
    Lnode*temp=p;
    
    for(int i=1;i<=n;i++){
        int elem;
        scanf("%d",&elem);
        Lnode*newnode=(Lnode*)malloc(sizeof(Lnode));
        newnode->data=elem;
        newnode->next=NULL;
        temp->next=newnode;
        temp=newnode;
    }

    Lnode*pre=NULL,*cur=p->next,*next=NULL;
    while(cur!=NULL){
        next=cur->next;
        cur->next=pre;
        pre=cur;
        cur=next;
    }
    p->next=pre;

    Lnode*tar=p->next;
    while(tar!=NULL){
        printf("%d ",tar->data);
        tar=tar->next;
    }
    printf("\n");

    //释放内存
    Lnode*curr=p;
    while(curr!=NULL){
        Lnode *next=curr->next;
        free(curr);
        curr=next;
    }
    return 0;
}