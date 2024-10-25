#include <stdio.h>
#include <stdlib.h>
//*分而治之
//*——将问题划分为不相交的子问题（一般使用递归不断将问题划分）
//*改进快速排序

void swap(int*a,int*b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
//*分区
void partition3(int a[],int l,int r,int*less,int*more){//传入的是指针(地址变量),可以带出
    *less=l,*more=r;//!!! *别忘记了

    int p=a[l];
    int i=l;

    while(i<=*more){
        if(a[i]>p){
            swap(&a[i],&a[*more]);
            (*more)--;
        }
        else if(a[i]==p){
            i++;
        }
        else if(a[i]<p){
            swap(&a[i],&a[*less]);
            (*less)++;
            i++;
        }
    }
}

void quickSort3(int a[],int l,int r){
    int less,more;
    //*用到递归时一定有一个基本情况（该情况下不用再调用递归，即递归的出口）
    if(l>=r){
        return;
    }
    //*随机确定基准
    int k=l+rand()%(r-l+1);
    swap(&a[l],&a[k]);
    //分区
    partition3(a,l,r,&less,&more);
    //递归左右两部分
    quickSort3(a,l,less-1);
    quickSort3(a,more+1,r);
}

int main(){
    int n;
    scanf("%d",&n);
    int a[n];

    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    quickSort3(a,0,n-1);

    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}