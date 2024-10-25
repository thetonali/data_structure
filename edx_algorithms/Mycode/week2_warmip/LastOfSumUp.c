#include <stdio.h>
#include <math.h>

//不用递归（太慢了）
//* 用迭代
int f(int n){
    if(n==0)
        return 0;
    long long a=0,b=1;
    for(int i=2;i<=n;i++){
        long long next=(a+b)%10;
        a=b;
        b=next;
    }
    return b;
}

int main(){
    int m,n;
    scanf("%d %d",&m,&n);

    int sum1=0,sum2=0;
    for(int i=0;i<m;i++){
        sum1+=f(i);
        sum1%=10;
    }
    for(int i=0;i<=n;i++){
        sum2+=f(i);
        sum2%=10;
    }
    printf("%d\n",(10+sum2-sum1)%10); //有可能sum2<sum1
}