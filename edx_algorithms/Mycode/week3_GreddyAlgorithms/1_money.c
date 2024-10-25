#include <stdio.h>
//贪心算法，优先选择面值大的纸币

int change(int m){
    int count=0;
    while(m>0){
        if(m<5)
            return count+m;
        else if(m>5&&m<10)
            return count=count+1+(m-5);
        else{
            m-=10;
            count++;
        }
    }
    return count;
}

int main(){
    int m;
    scanf("%d",&m);
    int res=change(m);
    printf("%d\n",res);
    return 0;
}