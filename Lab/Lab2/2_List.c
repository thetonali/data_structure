#include <stdio.h>
#include <stdlib.h>

typedef struct lnode{
    int data;
    struct lnode*next;
}Lnode,*LinkList;

void insertNode(LinkList p,int k){
    Lnode *cur=p;
    while(cur->next!=NULL && cur->next->data<k){
        cur=cur->next;
    }
    Lnode *key=(Lnode*)malloc(sizeof(Lnode));
    key->data=k;
    key->next=cur->next;
    cur->next=key;
}

int main(){
    int n,k;
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
    
    scanf("%d",&k);
    insertNode(p,k);
    
    Lnode*tar=p->next;
    while(tar!=NULL){
        printf(" %d",tar->data);
        tar=tar->next;
    }
    printf("\n");

    Lnode*cur=p;
    while(cur!=NULL){
        Lnode*next=cur->next;
        free(cur);
        cur=next;
    }
    return 0;
}