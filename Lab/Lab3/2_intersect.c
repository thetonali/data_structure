#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node*next;
}Lnode,*Link;

Lnode*creatnode(int x){
    Lnode*newnode=(Lnode*)malloc(sizeof(Lnode));
    newnode->data=x;
    newnode->next=NULL;
    return newnode;
}

Lnode*creatlink(Lnode*tail,int x){
    Lnode*newnode=creatnode(x);
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
            tmp=creatlink(tmp,ele);
        }
    }
    return head;
}

Lnode* Intersect(Link s1,Link s2){
    Lnode*cur1=s1;
    Lnode*cur2=s2;
    Lnode*newp=creatnode(0);
    Lnode*p=newp;
    while(cur1&&cur2){
        if(cur1->data > cur2->data){
            cur2=cur2->next;
        }
        else if(cur1->data < cur2->data){
            cur1=cur1->next;
        }
        else{
            p=creatlink(p,cur1->data);
            cur1=cur1->next;
            cur2=cur2->next;
        }
    }
    return newp;
}

int main(){
    Lnode*s1=readS();
    Lnode*s2=readS();

    Lnode*newp=Intersect(s1,s2);
    Lnode*tmp=newp->next;
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