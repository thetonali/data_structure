#include <stdio.h>
#define N 1005


//* 快速排序
/*
基于分治法的高效排序算法
* 1.选定基准：
  从数组中选择一个元素作为基准(pivot),可以是第一个、最后一个或随机选择的元素。
* 2.划分数组:
  将数组中比基准小的元素放在基准左侧，比基准大的放在基准右侧。
* 3.递归排序：
  对基准左右两侧的子数组递归进行快速排序。
* 4.合并结果：
  由于左右两侧的排序是原地进行的，无需额外的合并步骤。
*/
void swap(int*a,int*b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
//分区函数
int part(int arr[],int low,int high){
    int p=arr[high];//选择最后一个元素作为基准
    int i=low-1;//i是小于P区域的最后一个元素的索引

    for(int j=low;j<high;j++){
        if(arr[j]<p){//当前元素小于基准
            i++;
            swap(&arr[i],&arr[j]);//交换arr[i]和arr[j]
        }
    }
    //最后将基准元素放到正确位置
    swap(&arr[i+1],&arr[high]);
    return i+1;//返回基准元素的索引
}

//快速排序递归函数
void quickSort(int arr[],int low,int high){
    if(low<high){
        //找到基准元素的正确位置
        int pi=part(arr,low,high);

        //分别对基准左边和右边的元素递归排序
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int a[N],b[N];
    int t=2;
    for(int i=1;i<=n;i++){
      scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
      scanf("%d",&b[i]);
    }

    quickSort(a,1,n);
    quickSort(b,1,n);

    int sum=0;
    for(int i=1;i<=n;i++){
      sum+=a[i]*b[i];
    }
    printf("%d\n",sum);
    return 0;
}