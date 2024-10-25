#include <stdio.h>
#include <stdlib.h>
/*
*判断2个单链表是否相交
两个单链表相交——有公共的节点(1个或多个)
*(1)分别遍历链表1和链表2，对1中每个节点依次和2中各个节点比对
    查看它们的存储地址是否相同。相同则相交。
*注意：比较的是存储地址，不是存储元素。
*/

typedef struct Link{
    char elem;//数据域
    struct Link*next;//指针域
}link; //link为节点名，每个节点都是一个link结构体

//自定义的bool类型
typedef enum bool{
    False=0,
    True=1
}bool;

//L1和L2为2个单链表，函数返回True表示链表相交,返回False表示不相交
bool LinkIntersect(link*L1,link*L2){
    link*p1=L1;
    link*p2=L2;
    //遍历L1链表中的各个节点
    while(p1){
        //遍历L2链表，针对每个p1,依次和p2所指节点做比较
        while(p2){
            //p1、p2中记录的就是各个节点的存储地址，直接比较即可
            if(p1==p2){
                return True;
            }
            p2=p2->next;
        }
        p1=p1->next;
    }
    return False;
}


//*优化1，易知如果2个链表相交，则最后一个节点必定相同
bool LinkIntersect1(link*L1,link*L2){
    link*p1=L1;
    link*p2=L2;
    //找到L1链表中的最后一个节点
    while(p1->next){
        p1=p1->next;
    }
    //找到L2链表中的最后一个节点
    while(p2->next){
        p2=p2->next;
    }
    //判断L1和L2链表最后一个节点是否相同
    if(p1==p2){
        return True;
    }
    return False;
}

//*优化2，如果2个链表相交，那么相交部分节点的数量一定是相等的
//从L1尾部选取和L2链表等长的子链表temp，同时遍历temp和L2链表；节点相同则表明相交
bool LinkIntersect2(link*L1,link*L2){
    link*plong=L1;
    link*pshort=L2;
    link*temp=NULL;
    int num1=0,num2=0,step=0;

    //得到L1长度
    while(plong){
        num1++;
        plong=plong->next;
    }
    while(pshort){
        num2++;
        pshort=pshort->next;
    }
    //重置plong和pshort,使plong代表较长的链表,pshort代表较短的链表
    plong=L1;
    pshort=L2;
    step=num1-num2;
    if(num1<num2){
        plong=L2;
        pshort=L1;
        step=num2-num1;
    }
    //在plong链表中找到和pshort等长度的子链表
    temp=plong;
    while(step){
        temp=temp->next;
        step--;
    }
    //逐个比较temp和pshort链表中的节点是否相同
    while(temp&&pshort){
        if(temp==pshort){
            return True;
        }
        temp=temp->next;
        pshort=pshort->next;
    }
    return False;
}
//这个方法可以找到相交的那个交点