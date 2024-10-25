#include <stdio.h>
#define N 205

int n,m;
int arr[N];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    m=m%n;
    
    for(int i=n-1;i>=0;i--)
        arr[i+m]=arr[i];
    for(int i=0;i<m;i++)
        arr[i]=arr[i+n];

    printf("%d",arr[0]);
    for(int i=1;i<n;i++)
        printf(" %d",arr[i]);
    printf("\n");
    return 0;
}