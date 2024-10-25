#include "zlist.h"
//* 如何实现单链表的反转
/*
* 1.迭代反转法
* 2.递归反转法（更适用于不带头节点的链表
* 3.就地逆置法
* 4.头插法*/

//* 1.迭代反转链表
/*
  从首元节点遍历至链表的最后一个节点。
  期间逐个改变所遍历到的节点的指针域，令其指向前一个节点。
* 具体实现：
  借助三个指针beg,mid,end
  初始指向——beg=NULL,mid=首元,end=mid的下一个
  * 三个指针每次各向后移动一个节点，直至mid指向链表中最后一个节点（此时end为NULL
    注意：每次移动前，需要改变mid所指节点的指针域，令其指向和beg相同*/
//迭代反转法，head为无头节点链表的头指针
link* iteration_reverse(link* head){
  if(head==NULL||head->next==NULL){
    return head;
  }
  else{
    link*beg=NULL;
    link*mid=head;
    link*end=head->next;
    //一直遍历
    while(1){
      //修改mid所节点的指向
      mid->next=beg;
      //此时判断end是否为NULL，如果成立则退出循环
      if(end==NULL){
        break;
      }
      //整体向后移动3个指针
      beg=mid;
      mid=end;
      end=end->next;
    }
    //最后修改head头指针的指向
    head=mid;
    return head;
  }
}

//* 2.递归反转链表
/*
  和迭代法思想相反，递归反转法
  * 从链表的尾节点开始，依次向前遍历，遍历过程中依次改变各节点的指向。令其指向前一节点*/
link* recursive_reverse(link*head){
  //递归的出口
  if(head==NULL|| head->next==NULL){//空链或只有一个节点，直接返回头指针
    return head;
  }
  else{
    //一直递归，找到链表中最后一个节点
    link*new_head=recursive_reverse(head->next);

    //当逐层退出是，new_head的指向都不变，一直指向原链表中最后一个节点；
    //递归每退出一层，函数中head指针的指向都会发生改变，都指向上一个节点。

    //每退出一层，都需要改变head->next节点指针域的指向，同时令head所指节点的指针域为NULL。
    head->next->next=head;
    head->next=NULL;
    //每一层递归结束，都要将新的头指针返回给上一层。
    //由此即可保证整个递归过程中，能够一直找得到新链表的表头
    return new_head;
  }
}


//*头插法反转链表
/*
在原有链表的基础上，依次将位于链表头部的节点摘下，
然后采用从头部插入的方式生成一个新链表，此链表即为原链表的反转版。
*1.创建一个新的空链表
*2.从原链表中摘除头部节点,并以头部插入的方式将该节点添加到新链表
*/
link*head_reverse(link*head){
  link*new_head=NULL;
  link*temp=NULL;
  if(head==NULL||head->next==NULL){
    return head;
  }
  while(head!=NULL){
    temp=head;
    //将temp从head中摘除
    head=head->next;

    //将temp插入到new_head的头部
    temp->next=new_head;
    new_head=temp;
  }
  return new_head;
}


//*4.就地逆置法反转链表
/*
与头插法实现思想类似。
但头插法是建立一个新链表，而就地逆置法是直接对原链表做修改
*需要额外借助2个指针beg和end
*1.初始状态下,令beg指向第一个节点,end指向beg->next
*2.将end所指节点从链表上摘除，然后添加至当前链表的头部
*3.将end指向beg->next。重复。
*/
link*local_reverse(link*head){
  link*beg=NULL;
  link*end=NULL;
  if(head==NULL||head->next==NULL){
    return head;
  }
  beg=head;
  end=beg->next;
  while(end!=NULL){
    //将end从链表中摘除
    beg->next=end->next;
    //将end移动至链表头
    end->next=head;
    head=end;
    //调整end的指向，令其指向beg后的一个节点，为反转下一个节点做准备
    end=beg->next;
  }
  return head;
}

int main(){
  link*p=initLink();
  display(p);
  link*p1=iteration_reverse(p);
  display(p1);

  p=initLink();
  link*p2=recursive_reverse(p);
  display(p2);

  p=initLink();
  link*p3=head_reverse(p);
  display(p3);

  p=initLink();
  link*p4=local_reverse(p);
  display(p4);

  return 0;
}