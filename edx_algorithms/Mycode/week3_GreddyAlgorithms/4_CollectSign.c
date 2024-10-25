#include <stdio.h>
#include <stdlib.h>

//贪心算法。
//每次选择线段的右端点作为标记点，
//然后将所有包含这个点的线段移除，直到处理完所有线段

//定义结构体表示线段
typedef struct{
    int beg;
    int end;
}Segment;

//比较函数，用于按线段的右端点进行排序
/*
确保我们能在每次选择时优先考虑最早结束的线段，
这样可以最大限度地减少标记点的数量。
*/
int compare(const void*a,const void*b){
    Segment*segA=(Segment*)a;
    Segment*segB=(Segment*)b;
    return segA->end-segB->end; //从小到大
}
/*
compare 函数的参数是两个 void* 类型的指针 a 和 b。
这是因为 qsort 函数可以处理任何类型的数据，
因此它的`比较器`必须接受
*泛型指针（void*），
表示可以指向任何类型的数据。
*/

int main(){
    int n;
    scanf("%d",&n);//输入线段的数量

    Segment segments[n];

    //输入每个线段的起始和终止点
    for(int i=0;i<n;i++){
        scanf("%d %d",&segments[i].beg,&segments[i].end);
    }

    //按照右端点对线段进行排序
    qsort(segments,n,sizeof(Segment),compare);
    /*qsort 是 C 标准库中的一个快速排序函数，它能够对数组进行排序。
    qsort 的实现基于快速排序算法，具有平均情况下𝑂(𝑛log𝑛)的时间复杂度。
    这个函数非常灵活，可以用于排序任意类型的数据，
    只要你提供一个比较函数来指定排序的规则。
    */

    int points[n];//用于存储选择的标记点
    int poinCount=0;//记录选择了多少个标记点

    int lastPoint=-1;//上一个标记点的位置
    for(int i=0;i<n;i++){
        //如果当前线段的左端点在上一个标记点之后
        //选择该线段的右端点作为新的标记点
        if(segments[i].beg>lastPoint){
            lastPoint=segments[i].end;
            points[poinCount++]=lastPoint;
        }
    }

    //输出最少的标记点数量
    printf("%d\n",poinCount);

    //输出这些标记点
    for(int i=0;i<poinCount;i++){
        printf("%d ",points[i]);
    }
    printf("\n");

    return 0;
}