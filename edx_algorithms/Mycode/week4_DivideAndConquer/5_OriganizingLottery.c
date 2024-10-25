#include <stdio.h>
#include <stdlib.h>
//*扫描线性算法
//本质上是通过一次排序和线性扫描来解决问题,并没有进行递归分解
//依赖排序和事件驱动高效处理问题。

//定义区间和点的结构体
typedef struct{
    int x; //坐标
    int type; //类型(0表示点,1表示区间左端点,2表示区间右端点)
    int index; //点的索引,用于记录原始位置
}Event;

//比较函数,用于排序事件
int cmp(const void*a,const void*b){
    Event *event1=(Event*)a;
    Event *event2=(Event*)b;
    //如果位置相同,按照类型排序:左端点<点<右端点
    if(event1->x==event2->x){
        return event1->type-event2->type;
    }
    return event1->x-event2->x;
}

//使用扫描线算法统计每个点被包含的区间数量
void count_seg(int s,int p,int segments[][2],int points[],int result[]){
    int totalEvents=2*s+p;
    Event *events=(Event*)malloc(totalEvents*sizeof(Event));
    int eventIndex=0;

    //创建区间的开始和结束事件
    for(int i=0;i<s;i++){
        events[eventIndex++]=(Event){segments[i][0],1,-1};//段开始
        events[eventIndex++]=(Event){segments[i][1],2,-1};//段结束
    }

    //创建点的事件
    for(int i=0;i<p;i++){
        events[eventIndex++]=(Event){points[i],0,i};//点,记录其在输入中的索引
    }

    //对所有事件按照位置进行排序
    qsort(events,totalEvents,sizeof(Event),cmp);

    //扫描线算法,统计当前活跃的区间数量
    int actSeg=0;
    for(int i=0;i<totalEvents;i++){
        if(events[i].type==1){ //遇到段的开始,活跃区间数加一
            actSeg++;
        }
        else if(events[i].type==2){  //遇到段的结束,活跃区间数减一
            actSeg--;
        }
        else if(events[i].type==0){  //遇到点,记录当前活跃区间数
            result[events[i].index]=actSeg;
        }
    }

    free(events);
}


int main(){
    int s,p; //读取段的数量和点的数量
    scanf("%d %d",&s,&p);

    int segments[s][2]; //存储每个段的起点和终点
    int points[p];  //存储每个点的位置
    int results[p]; //存储每个点的结果

    //读取段的信息
    for(int i=0;i<s;i++){
        scanf("%d %d",&segments[i][0],&segments[i][1]);
    }
    //读取点的信息
    for(int i=0;i<p;i++){
        scanf("%d",&points[i]);
    }

    //使用扫描线法计算每个点被包含的段数
    count_seg(s,p,segments,points,results);

    for(int i=0;i<p;i++){
        printf("%d ",results[i]);
    }
    return 0;
}