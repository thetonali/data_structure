//贪心算法，最后一名给1个
#include <stdio.h>

/*
如果当前 *剩余的n 小于或等于我们要加入的下一个整数，
则将剩余部分加入到最后一个数中。
* 不要比较sum了。。。
*/

int main(){
    int n;
    scanf("%d",&n);

    int sum=0,k=1,num[n]; //当前总和，当前要加入的数字，存储所有的k

    int count=0;//记录有多少个数字
    while(n>=k){
        n-=k;
        num[count++]=k;
        k++;
    }

    //如果还有剩余值，将其加入到最后一个数
    if(n>0){
        num[count-1]+=n; //* count++了！！！
    }

    printf("%d\n",count);
    for(int i=0;i<count;i++){
        printf("%d ",num[i]);
    }
    printf("\n");
    return 0;

}