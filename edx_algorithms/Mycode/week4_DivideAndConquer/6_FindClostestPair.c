#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

//定义点结构体
typedef struct{
    int x,y;
}Point;

//计算两点间欧式距离
double distance(Point a,Point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

//按x坐标对点进行排序(快速排序)
int cmpX(const void*a,const void*b){
    Point* p1=(Point*)a;
    Point* p2=(Point*)b;
    return (p1->x-p2->x);
}
//按y坐标排序
int cmpY(const void*a,const void*b){
    Point* p1=(Point*)a;
    Point* p2=(Point*)b;
    return (p1->y-p2->y);
}

//对少量点使用暴力方法计算最近距离
double bruteForce(Point points[],int n){
    double min=DBL_MAX;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            double d=distance(points[i],points[j]);
            if(d<min){
                min=d;
            }
        }
    }
    return min;
}

//在strip中查找最近点对(假设strip中的点已经按y坐标排序)
double stripClosest(Point strip[],int size,double delta){
    double min=delta;

    for(int i=0;i<size;i++){
        for(int j=i+1;j<size && (strip[j].y-strip[i].y)<min;j++){
            double d=distance(strip[i],strip[j]);
            if(d<min){
                min=d;
            }
        }
    }
    return min;
}

//递归解决最近点对问题
double closeUtil(Point pSortedX[],Point pSortedY[],int n){
    //基本情况:当点的数量较少时，暴力破解
    if(n<=3){
        return bruteForce(pSortedX,n);
    }

    //将点集分为两半
    int mid=n/2;
    Point midP=pSortedX[mid];

    //分别递归解决左半部分和右半部分
    Point left_by_y[mid+1];
    Point right_by_y[n-mid-1];
    int li=0,ri=0;
    for(int i=0;i<n;i++){
        if(pSortedY[i].x<=midP.x){
            left_by_y[li++]=pSortedY[i];
        }
        else{
            right_by_y[ri++]=pSortedY[i];
        }
    }

    double delta_left=closeUtil(pSortedX,left_by_y,mid);
    double delat_right=closeUtil(pSortedX+mid,right_by_y,n-mid);

    //找到最小的delta
    double delta=fmin(delta_left,delat_right);

    //建立中间的strip,考虑跨越中线的点
    Point strip[n];
    int strip_size=0;
    for(int i=0;i<n;i++){
        if(fabs(pSortedY[i].x-midP.x)<delta){
            strip[strip_size++]=pSortedY[i];
        }
    }
    return fmin(delta,stripClosest(strip,strip_size,delta));
}

//主函数
double closest(Point points[],int n){
    //创建两个数组,一个按x排序,一个按y排序
    Point points_sorted_by_x[n];
    Point points_sorted_by_y[n];
    for(int i=0;i<n;i++){
        points_sorted_by_x[i]=points[i];
        points_sorted_by_y[i]=points[i];
    }

    //按x和y分别排序
    qsort(points_sorted_by_x,n,sizeof(Point),cmpX);
    qsort(points_sorted_by_y,n,sizeof(Point),cmpY);

    //调用递归函数解决问题
    return closeUtil(points_sorted_by_x,points_sorted_by_y,n);
}

int main(){
    int n;
    scanf("%d",&n);

    Point points[n];
    for(int i=0;i<n;i++){
        scanf("%d %d",&points[i].x,&points[i].y);
    }

    //计算最近点对的距离
    double result=closest(points,n);

    //输出结果
    printf("%lf\n",result);
    return 0;
}