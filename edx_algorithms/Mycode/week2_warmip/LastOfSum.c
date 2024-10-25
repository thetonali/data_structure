#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int F[n];
    F[0]=0,F[1]=1;
    for(int i=2;i<=n;i++){
        F[i]=(F[i-1]+F[i-2])%10; //!!!
    }
    int sum=0;
    for(int i=0;i<=n;i++)
        sum+=F[i];
    printf("%d\n",sum%10);

    return 0;
}