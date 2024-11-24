#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10

typedef struct node{
    int left;
    int right;
}Node;
Node nodes[N];
int isChild[N];

void initTree(int n,Node nodes[],int isChild[]){
    for(int i=0;i<n;i++){
        char left[2],right[2];
        scanf("%s %s",left,right);
        if(strcmp(left,"-")==0)
            nodes[i].left=-1;
        else{
            nodes[i].left=atoi(left);
            isChild[nodes[i].left]=1;
        }
        
        if(strcmp(right,"-")==0)
            nodes[i].right=-1;
        else{
            nodes[i].right=atoi(right);
            isChild[nodes[i].right]=1;
        }
    }
}

int findRoot(int n,int isChild[]){
    for(int i=0;i<n;i++){
        if(isChild[i]!=1)
            return i;
    }
    return -1;
}

void printleaf(Node nodes[],int isChild[],int root){
    int q[N]={0},front=-1,rear=-1;
    q[++front]=root;
    rear++;
    
    int cur;
    while(front<=rear){
        cur=q[front--];
        if(isChild[cur])
            printf("%d",cur);
        if(nodes[cur].left!=-1)
            q[++rear]=nodes[cur].left;
        if(nodes[cur].right!=-1)
            q[++rear]=nodes[cur].right;
    }
}



int main(){
    int n;
    scanf("%d",&n);
    initTree(n,nodes,isChild);
    int root=findRoot(n,isChild);
    printleaf(nodes,isChild,root);
    return 0;
}