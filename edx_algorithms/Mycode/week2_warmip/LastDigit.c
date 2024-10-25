//找到第n个斐波那契数的最后一位数字
/*
* 斐波那契数列增长非常快
* 迭代
*/

#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int F[n];
    F[0]=0,F[1]=1;
    for(int i=2;i<=n;i++){
        F[i]=(F[i-1]+F[i-2])%10; //!!!
    }
    printf("%d",F[n]%10);
    return 0;
}