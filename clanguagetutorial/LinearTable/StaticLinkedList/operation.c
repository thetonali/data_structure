#include "initiate.h"
//*静态链表基本操作——增删改查

//*1.添加元素——将元素4添加到静态链表第3个位置
/*
*1.从备用链表中摘除一个节点,用于存储元素4
*2.找到表中第二个节点(添加位置的前一个节点,这里是数据元素2),将元素2的游标赋值给新元素4
*3.将元素4所在数组中的下标赋值给元素2的游标值*/

//向链表中插入数据,body表示链表的头节点在数组中的位置，add表示插入元素的位置,a表示要插入的数据
void insertArr(component*array,int body,int add,char a){
    int tmpBody=body;//tmpBody做遍历结构体数组使用
    //找到要插入位置的上一个节点在数组中的位置
    for(int i=1;i<add;i++){
        tmpBody=array[tmpBody].cur;
    }
    int insert=mallocArr(array); //申请空间,准备插入
    array[insert].data=a;

    array[insert].cur=array[tmpBody].cur; //新插入节点的游标等于其直接前驱节点的游标
    array[tmpBody].cur=insert; //直接前驱节点的游标等于新插入节点所在数组中的下标
}


//*2.删除元素——
/*
 *1.将存有目标元素的节点从数据链表中摘除
 *2.将摘除节点添加到备用链表,以便下次使用
  *提示——
   若问题涉及大量删除元素的操作,建议在建立静态链表之初创建一个带有头节点的静态链表，方便实现删除链表中第一个数据元素的操作*/

//备用链表回收空间的函数,其中array为存储数据的数组,k表示未使用节点所在数组的下标
void freeArr(component*array,int k){
    array[k].cur=array[0].cur;
    array[0].cur=k;
}
//删除节点函数,a表示被删除节点中数据域存放的数据
void deletArr(component*array,int body,char a){
    int tmpBody=body;
    //找到被删除节点的位置
    while(array[tmpBody].data!=a){
        tmpBody=array[tmpBody].cur;
        //!当tmpBody为0时,表示遍历结束,说明链表中没有存储该数据的节点
        if(tmpBody==0){
            printf("链表中没有此数据");
            return;
        }
    }
    //运行到此处,说明有该节点
    int del=tmpBody;
    tmpBody=body;
    //找到该节点的上一个节点,做删除操作  !!!上一个节点！
    while(array[tmpBody].cur!=del){
        tmpBody=array[tmpBody].cur;
    }
    //将被删除节点的游标直接给被删除节点的上一个节点
    array[tmpBody].cur=array[del].cur;
    //回收被摘除节点的空间
    freeArr(array,del);
}

int main(){
    component array[maxSize];
    int body=initArr(array);
    printf("静态链表为:\n");
    displayArr(array,body);
    return 0;
}


