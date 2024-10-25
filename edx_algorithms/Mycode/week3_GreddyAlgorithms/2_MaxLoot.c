#include <stdio.h>
#include <stdlib.h>
//贪心算法
/*
* BestItem(w1,v1,...,wn,vn)
  maxValuePerWeight=0
  bestItem=0
  for i from 1 to n:
    if wi>0:
        if (vi/wi) > maxValuePerWeight:
            maxValuePerWeight=(vi/wi)
            bestItem=i
  return bestItem
* Knapsack(W,w1,v1,...wn,vn)
  amounts=[0,0,...,0]
  totalValue=0
  repeat n tomes:
    if W=0:
        return (totalValue,amounts)
    i=BestItem(w1,v1,...,wn,vn)
    a=min(wi,W)
    totalValue=totalValue+a*(vi/wi)
    wi=wi-a
    amounts[i]=amounts[i]+a
    W=W-a
  return (totalValue,amounts)
*/
/*
assume (v1/w1)>(v2/w2)>(v3/w3)...>(vn/wn)
* KnapsaackFast(W,w1,v1,....,wn,vn)
  amounts=[0,0,...,0]
  totalValue=0
  for i from 1 to n:
    if W=0:
        return (totalValue,amounts)
    a=min(w1,W)
    totalValue=totalValue+a*(vi/wi)
    wi=wi-a
    amounts[i]=amounts[i]+a
    W=W-a
  return (totalValue,amounts)
* 
*/

#define N 1005

int BestItem(int w[],int v[],int n){
    double maxPer=0.0;
    int best=0;
    for(int i=1;i<=n;i++){
        if(w[i]>0){
            double per=(v[i]*1.0)/w[i];
            if(per>maxPer){
                maxPer=per;
                best=i;
            }
        }
    }
    return best;
}//找到价值最高的下标索引

int min(int a,int b){
    if(a<=b)
        return a;
    else
        return b;
}

int main(){
    int n,W;
    scanf("%d %d",&n,&W);
    int v[N], w[N];
    for(int i=1;i<=n;i++){
        scanf("%d %d",&v[i],&w[i]);
    }

    double totalValue=0; //所求
    int besti;
    for(int i=1;i<=n;i++){ //遍历所有的东西
        if(W==0){
            printf("%.4f\n", totalValue);
            return 0;
        }
        besti=BestItem(w,v,n);
        int a=min(W,w[besti]);
        totalValue+=a*(1.0*v[besti]/w[besti]);
        w[besti]-=a;
        W-=a;
    }
    printf("%.4f\n",totalValue);
    return 0;
}