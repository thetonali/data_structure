#include <stdio.h>
#include <string.h>
#include <ctype.h>

int priority(char ope){
    switch(ope){
        case '+':
        case '-':return 1;
        case '*':
        case '/':return 2;
        default:return 0;
    }
}

void transfer(char*infix,char*postfix){
    char ope[21];
    int top=-1;
    int j=0;
    for(int i=0;i<strlen(infix);i++){
        char c=infix[i];
        if(isdigit(c))
            postfix[j++]=c;
        else if(c=='(')
            ope[++top]=c;
        else if(c==')'){
            while(top!=-1 && ope[top]!='(')
                postfix[j++]=ope[top--];
            top--;
        }
        else{
            while(top!=-1 && priority(c)<=priority(ope[top]))
                postfix[j++]=ope[top--];
            ope[++top]=c;
        }
    }
    while(top!=-1){
        postfix[j++]=ope[top--];
    }
    postfix[j]='\0';
}

int applyop(int a,int b,char c){
    switch(c){
        case '+':return a+b;
        case '-':return a-b;
        case '*':return a*b;
        case '/':return a/b;
    }
    return 0;
}

int calcute(char*postfix){
    int value[21];
    int top=-1;
    for(int i=0;i<strlen(postfix);i++){
        char c=postfix[i];
        if(isdigit(c))
            value[++top]=c-'0';
        else{
            int a=value[top--],b=value[top--];
            value[++top]=applyop(b,a,c);
        }
    }
    return value[top];
}

int main()
{
    int N;
    scanf("%d",&N);
    while(N--){
        char infix[21],postfix[21];
        scanf("%s",infix);
        transfer(infix,postfix);
        for(int i=0;i<strlen(postfix);i++){
            printf("%c",postfix[i]);
        }
        int res=calcute(postfix);
        printf(" %d\n",res);
    }
    return 0;
}
