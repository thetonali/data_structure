//最大公约数
//* 辗转相除法
#include <stdio.h>

int GCD(int a,int b);
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d\n",GCD(a,b));
    return 0;
}


int GCD(int a,int b){
    if(a==0)
        return b;
    else if(b==0)
        return a;
    else if(a>b)
        a%=b;
    else if(b>a)
        b%=a;
    return GCD(a,b);
}