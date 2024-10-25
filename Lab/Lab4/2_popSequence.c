#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct sqStack{
    int*data;
    int top;
    int maxSize;
}Stack;

Stack* initStack(int m){
    Stack* s;
    s=(Stack*)malloc(sizeof(Stack));
    s->data=(int*)malloc(sizeof(int)*m);
    s->top=0;
    s->maxSize=m;
    return s;
}

bool isEmpty(Stack*s){
    if(s->top==0)
        return true;
    return false;
}
bool isFull(Stack*s){
    if(s->top==s->maxSize)
        return true;
    return false;
}

void push(Stack*s,int x){
    if(isFull(s))
        return;
    s->top++;
    s->data[s->top]=x;
    return;
}
void pop(Stack*s){
    if(isEmpty(s))
        return;
    s->top--;
}

bool checkpop(Stack*s,int a[],int n){
    int index=0;
    for(int i=1;i<=n;i++){
        if(isFull(s))
            return false;
        push(s,i); 
        while(s->data[s->top]==a[index]){
            pop(s);
            index++;
        }
    }
    if(isEmpty(s))
        return true;
    return false;
}

int main(){
    int m,n,k;
    scanf("%d %d %d",&m,&n,&k);
    Stack*s;
    int a[n];
    while(k--){
        s=initStack(m);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        if(checkpop(s,a,n))
            printf("YES\n");
        else{
            printf("NO\n");
        }
        free(s->data);
        free(s);
    }
    return 0;
}