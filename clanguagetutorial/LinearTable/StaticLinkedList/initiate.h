#include <stdio.h>
#include <stdlib.h>
//*静态链表！！！数组
/*
* 线性存储结构的一种,兼顾了顺序表和链表的优点。(数组+游标)
    *数据存储在数组中(和顺序表一样)
    *但存储位置是随机的,数据之间"一对一"的逻辑关系通过一个int变量(称为"游标",和指针功能类似)维持(和链表类似)
     游标——此变量用于指明各个元素的直接后继元素所在数组中的位置下标
* 静态链表的起始位置和结束位置
    *通常静态链表会将第一个数据元素放到数组下标为1的位置(a[1])中
    *链表的最后一个元素——游标变量=0(a[0]，存有数据说明数组已满)
* 静态链表的节点
    *数据域：存储数据元素
    *游标：数组下标*/
typedef struct{
    int data; //数据域
    int cur; //游标
}component;


//*备用链表
/*
  静态链表中，除了数据本身通过游标组成的链表外,
    *还需要有一条连接各个空闲位置的链表,称为备用链表
    *备用链表的作用是回收数组中未使用或之前使用过(目前未使用)的存储空间,留待后期使用。
  即两条链表——1.连接数据；2.连接数组中未使用的空间
  *通常，备用链表的表头位于数组下标为0的位置,而数据链表的表头位于数组下标为1的位置。
  *设置备用链表的好处——
    清楚知道数组中是否有空闲位置，以便数据链表添加新数据时使用*/


//*静态链表的创建
/*
* 1.数据链表未初始化时，数组中所有位置处于空闲状态，因此都应被链接在备用链表上
    当向静态链表中添加数据时需提前从备用链表中摘除节点，以供新数据使用
    *备用链表摘除节点最简单的方法是——摘除a[0]的直接后继节点；同样向备用链表中添加空闲节点也是添加作为a[0]新的直接后继节点；
     因为a[0]是备用链表的第一个节点,知道其位置，操作直接后继节点相对容易，无需遍历备用链表。*/

#define maxSize 6
//将结构体数组中所有分量链接到备用链表中
void reserveArr(component*array);
//初始化静态链表
int initArr(component *array);
//输出函数
void displayArr(component*array,int body);
//从备用链表上摘下空闲节点的函数
int mallocArr(component*array);

//创建备用链表
void reserveArr(component *array){
    for(int i=0;i<maxSize;i++){
        array[i].cur=i+1;//将每个数组分量链接到一起
        array[i].data=-1;
    }
    array[maxSize-1].cur=0; //链表最后一个节点的游标值为0
}

//游标值=0，是链表的最后一个节点
//提取分配空间
int mallocArr(component*array){
    //若备用链表为空,则返回分配的节点下标，否则返回0(当分配最后一个节点时，该节点的游标值是0)
    int i=array[0].cur;
    if(array[0].cur!=0){ //a[0]不是最后一个节点
        array[0].cur=array[i].cur; //摘除a[0]后面那个节点
    }
    return i;
}

//初始化静态链表
int initArr(component*array){
    reserveArr(array);
    int body=mallocArr(array); //?有头节点
    //声明一个变量,把它当做指针用，指向链表的最后一个节点。因为链表为空，所以和头节点重合
    int tmpBody=body;
    for(int i=1;i<4;i++){
        int j=mallocArr(array); //从备用链表中拿出空闲的分量
        array[tmpBody].cur=j; //将申请的空闲分量链接在链表的最后一个节点后面
        array[j].data=i; //给新申请的分量的数据域初始化
        tmpBody=j;
    }
    array[tmpBody].cur=0; //新链表的最后一个节点的指针设置为0
    return body; //头节点(?)
}

void displayArr(component*array,int body){
    int tmpBody=body; //tmpBody准备做遍历使用
    while(array[tmpBody].cur){
        printf("%d,%d ",array[tmpBody].data,array[tmpBody].cur);
        tmpBody=array[tmpBody].cur;
    }
    printf("%d,%d\n",array[tmpBody].data,array[tmpBody].cur);

}

//!注意
//此代码创建了一个带有头节点的静态链表,最先输出的"-1,2"表示的是头节点；(-1表示此处为存储数据)
//其首元节点(存储元素1的节点)在数组array[2]中