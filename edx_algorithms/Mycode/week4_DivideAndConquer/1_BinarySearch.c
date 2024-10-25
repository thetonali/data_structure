#include <stdio.h>
//二分查找
int binary(int x,int l,int r,int a[]){
    int mid=0;
    while(l<r){
        mid=(l+r)/2;
        if(a[mid]==x)
            return mid;
        if(a[mid]<x){
            l=mid+1;
            binary(x,l,r,a);
        }else{
            r=mid-1;
            binary(x,l,r,a);
        }
    }
    return -1; //找不到
}

int n,k;
int main(){
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&k);
    int b[k];
    for(int i=0;i<k;i++){
        scanf("%d",&b[k]);
        int ans=binary(b[k],0,n,a);
        printf("%d ",ans);
    }
    return 0;
}