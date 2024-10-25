#include "zlist.h"

/*链表插入元素
* 插入头部，作为首元节点
* 插入中间
* 插入末尾，作为链表中最后一个数据元素
- *两个操作
    - 1.将新节点的next指针指向插入位置后的节点
    - 2.将插入位置前节点的next指针指向插入节点*/
//p为原链表，elem表示新数据元素，add表示新元素要插入的位置
link*insertElem(link*p,int elem,int add){
    link*temp=p;//创建临时节点temp
    //首先要找到插入位置的上一个节点
    for(int i=1;i<add;i++){
        temp=temp->next;
        if(temp==NULL){
            printf("Wrong Position!\n");
            return p;
        }
    }
    //创建插入节点c
    link*c=(link*)malloc(sizeof(link));
    c->elem=elem;
    //向链表中插入节点
    c->next=temp->next;
    temp->next=c;
    return p;
}


/*链表删除元素
* 1.将节点从链表中摘下来
    - *找到该节点的前驱节点temp。
* 2.手动释放节点，回收被节点占用的存储空间*/
//p为原链表，add为要删除元素的位置
link*delElem(link*p,int add){
    link*temp=p;
    //遍历到被删除节点的上一个节点
    for(int i=1;i<add;i++){
        temp=temp->next;
        if(temp->next==NULL){
            printf("Wrong Position!\n");
            return p;
        }
    }
    link*del=temp->next; //单独设置一个指针指向被删除节点，防止丢失
    temp->next=temp->next->next; //删除某个节点的方法就是更改前一个节点的指针域
    free(del); //手动释放该节点
    return p;
}


/*链表查找元素
* 从表头依次遍历表中节点，与被查找元素比对
  直至比对成功或遍历至链表最末端的NULL（比对失败的标识）*/
//p为原链表，elem表示被查找元素
int selectElem(link*p,int elem){
    //新建一个指针t，初始化为头指针p
    link*t=p;
    int i=1;//计数
    //由于头节点的存在，因此while中的判断为t->next
    while(t->next!=NULL){
        t=t->next; //越过头节点
        if(t->elem==elem){
            return i;
        }
        i++;
    }
    //程序执行到此处，表示查找失败
    return -1;
}

/*链表更新元素
* 通过遍历找到存储此元素的节点，对节点数据域做更改操作*/
//更新函数，add表示更改节点在链表中的位置，newElem为新的数据域的值
link*amendElem(link*p,int add,int newElem){
    link*temp=p;
    temp=temp->next;
    for(int i=1;i<add;i++){
        temp=temp->next;
    }
    temp->elem=newElem;
    return p;
}

int main(){
    link*p=inittLink();
    displayy(p);

    p=insertElem(p,5,4);
    displayy(p);

    p=delElem(p,3);
    displayy(p);

    int address=selectElem(p,2);
    printf("%d\n",address);

    p=amendElem(p,3,7);
    displayy(p);

    return 0;
}