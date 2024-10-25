#include <stdio.h>
//*分而治之！（常常使用递归法）
//*——将序列递归地分成两半，确定每一半中的多数元素，然后组合结果以确定整个序列的多数元素
/*
*1.基本情况：仅包含一个元素,则该元素是多数元素
*2.递归情况：
    * 递归地找到左半部分和右半部分的多数元素
    * 如果两半都返回相同元素,则这是多数元素
    * 如果返回不同元素,计算每个元素在整个数组中出现的次数,并确定哪一个(如果有)是多数元素
*/

int count_occur(int a[],int l,int r,int ele){
    int count=0;
    for(int i=l;i<=r;i++){
        if(a[i]==ele){
            count++;
        }
    }
    return count;
}

//分而治之法查找数组中的多数元素
int majority_ele(int a[],int l,int r){
    //基本情况：数组中只有一个元素时,该元素即为多数元素
    if(l==r){
        return a[l];
    }
    //将数组分为左右两部分
    int mid=(l+r)/2;
    int left_major=majority_ele(a,l,mid);
    int right_major=majority_ele(a,mid+1,r);
    //如果左右两部分的多数元素相同,则返回该元素
    if(left_major==right_major){
        return left_major;
    }
    //否则,计算两个多数元素在整个区间内的出现次数
    else{
        int left_count=count_occur(a,l,r,left_major);
        int right_count=count_occur(a,l,r,right_major);
        //返回出现次数多的元素
        if(left_count>right_count){
            return left_major;
        }
        else if(left_count<right_count){
            return right_major;
        }
        else{
            return -1;//没有多数元素
        }
    }
}

//检验是否存在多数元素
int has_majority_ele(int a[],int n,int l,int r){
    int major=majority_ele(a,l,r);

    int count=count_occur(a,l,r,major);
    if(count!=-1 && count>n/2){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    printf("%d\n",has_majority_ele(a,n,0,n-1));
    return 0;
}