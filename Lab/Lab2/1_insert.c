#include <stdio.h>

int main(){
    int n,key;
    scanf("%d",&n);
    int a[n+5];
    a[0]=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&key);

    for(int i=n;i>=0;i--){
        if(key<a[i]){
            a[i+1]=a[i];
        }
        else {
            a[i+1]=key;
            break;
        }
    }
    for(int i=1;i<=n+1;i++){
        printf(" %d",a[i]);
    }
    return 0;
}