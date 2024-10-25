#include "zlist.h"
/*创建链表
* 1.声明一个头指针（如果有必要，可以声明一个头节点）
* 2.创建多个存储数据的节点，在创建过程中随时与其前驱节点建立逻辑关系
*/
//link是一个节点。table是一个表。

int main(){
    //初始化链表
    link*p=inittLink();
    displayy(p);
    return 0;
}