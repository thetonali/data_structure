#include <stdio.h>
#include <stdlib.h>

int Merge(int a[],int tmp[],int l,int m,int r){
    int i=l;//左子数组的起始索引
    int j=m+1;//右子数组的起始索引
    int k=l;//临时数组的起始索引
    int inv_count=0;

    //合并两个子数组并计算逆序对
    while((i<=m)&&(j<=r)){
        if(a[i]<=a[j]){
            tmp[k++]=a[i++];
        }
        else{
            tmp[k++]=a[j++];
            inv_count+=(m-i+1);//计算逆序对
        }
    }

    //复制左子数组剩余元素(如果有)
    while(i<=m){
        tmp[k++]=a[i++];
    }
    //右子数组同理
    while(j<=r){
        tmp[k++]=a[j++];
    }

    //?为什么将排序后的子数组复制回原数组
    for(i=l;i<=r;i++){
        a[i]=tmp[i];
    }
    return inv_count;
}

//函数使用归并排序来排序数组并统计逆序对
int MergeSort(int a[],int tmp[],int l,int r){
    int mid,inv_count=0;
    if(l<r){//!不满足就是递归的出口
        mid=(l+r)/2;

        //递归排序左半部分并统计逆序对
        inv_count+=MergeSort(a,tmp,l,mid);  
        //!里面还会调用Merge函数，而此时Merge函数中的inv_count是局部变量；用return带出此时的count，然后累加！
        //!也可以用全局变量，此时不需要inv_count+=MergeSort(a,tmp,l,mid); 只需要调用MergeSort(a,tmp,l,mid); 
        //递归排序右半部分并统计逆序对
        inv_count+=MergeSort(a,tmp,mid+1,r);

        //合并两个字数组并统计跨子数组的逆序对
        inv_count+=Merge(a,tmp,l,mid,r);
    }
    return inv_count;

}

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    int tmp[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    //调用归并排序和统计逆序对函数
    int result=MergeSort(a,tmp,0,n-1);

    printf("%d\n",result);
    return 0;
}