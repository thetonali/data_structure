#include <stdio.h>
#include <stdlib.h>

typedef struct lnode{
    int data;
    struct lnode*next;
}Lnode;

Lnode* creatnode(int x){
    Lnode* newnode=(Lnode*)malloc(sizeof(Lnode));
    newnode->data=x;
    newnode->next=NULL;
    return newnode;
}
Lnode* insert(Lnode*tail,int data){
    Lnode*newnode=creatnode(data);
    if(tail!=NULL){
        tail->next=newnode;
    }
    return newnode;
}

Lnode*readS(){
    int ele;
    Lnode*head=NULL;
    Lnode*tmp=NULL;
    while(scanf("%d",&ele)&&ele!=-1){
        if(head==NULL){
            head=creatnode(ele);
            tmp=head;
        }
        else{
            tmp=insert(tmp,ele);
        }
    }
    return head;
}

int main(){
    Lnode*S1=readS();
    Lnode*S2=readS();
    Lnode*cur1=S1;
    Lnode*cur2=S2;

    Lnode*merge=creatnode(0);
    Lnode*cur=merge;
    while(cur1&&cur2){
        if(cur1->data<=cur2->data){
            cur->next=cur1;
            cur1=cur1->next;
        }
        else{
            cur->next=cur2;
            cur2=cur2->next;
        }
        cur=cur->next;
    }
    
    if(cur1){
        cur->next=cur1;
    }
    if(cur2){
        cur->next=cur2;
    }

    Lnode*tmp=merge->next;
    if(tmp==NULL){
        printf("NULL\n");
        return 0;
    }
    while(tmp->next){
        printf("%d ",tmp->data);
        tmp=tmp->next;
    }
    printf("%d\n",tmp->data);
    return 0;
}