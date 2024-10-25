#include <stdio.h>
#include <stdlib.h>
typedef struct Link{
    int elem; //代表数据域
    struct Link* next; //代表指针域，指向直接后继元素
}link; //link为节点名，每个节点都是一个link结构体

/*
由于指针域中的指针要指向的也是一个节点，因此要声明为Link类型
* 头节点，头指针，首元节点
  1.头指针：一个普通的指针，永远指向链表第一个节点的位置。
    头指针用于指明链表的位置，以便后期找到链表并使用表中的数据
  2.节点：链表中的节点又细分为头结点、首元节点和其他节点
    * 头节点：一个不存任何数据的空节点，通常作为链表的第一个节点。
      头节点不是必须的，其作用是为了方便解决某些实际问题。
    * 首元节点：由于头节点（也就是空节点）的缘故，链表中第一个存有数据的节点称为首元节点。
      首元节点只是对链表中第一个存有数据的节点的一个称谓，没有实际意义。
    - 其他节点：略。
  * 链表中有头节点时，头指针指向头节点；反之，头指针指向首元节点。
*/

void display(link*p){//无头节点
  link*temp=p; //!将temp指针重新指向头节点
  //只要temp指针指向的节点next不是NULL，就执行输出语句
  while(temp!=NULL){
    printf("%d ",temp->elem);
    temp=temp->next;
  }
  printf("\n");
}

void displayy(link*p){//有头节点
  link*temp=p;
  while(temp->next!=NULL){
    printf("%d ",temp->next->elem);
    temp=temp->next;
  }
  printf("\n");
}

//含头节点
link* inittLink(){
    link*p=(link*)malloc(sizeof(link));//头节点
    link*temp=p;//声明一个指针指向头节点

    for(int i=1;i<5;i++){
        link*a=(link*)malloc(sizeof(link));
        a->elem=i;
        a->next=NULL;
        temp->next=a;
        temp=temp->next;
    }
    return p;
}

//不含头节点
link* initLink(){
    link*p=NULL; //创建头指针
    link*temp=(link*)malloc(sizeof(link)); //创建首元节点
    //* 首元节点初始化
    temp->elem=1;
    temp->next=NULL;
    p=temp; //头指针指向首元节点
    //从第二个节点开始创建
    for(int i=2;i<5;i++){
        //创建一个新节点并初始化
        link*a=(link*)malloc(sizeof(link));
        a->elem=i;
        a->next=NULL;
        //将temp节点与新建立的节点a建立逻辑关系
        temp->next=a;
        //指针temp每次都指向新链表的最后一个节点！
        temp=a;//temp=temp->next
    }
    //返回建立的节点，只返回头指针p即可。通过头指针即可找到整个链表。
    return p;
}