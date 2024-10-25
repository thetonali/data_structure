#include <stdio.h>
//*递归
int Fibonacci(int n){
    if(n<=1)
        return n;
    else
        return Fibonacci(n-1)+Fibonacci(n-2);
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",Fibonacci(n));
    return 0;
}