#include "public.h"
/*
* 顺序表的初始化
1.给head动态数组申请足够大小的物理空间
2.给size和length赋值*/
table initTable(){
  table t;
  t.head=(int*)malloc(Size*sizeof(int));//构造一个空的顺序表，动态申请存储空间
  if(!t.head){//申请失败则做出提示并退出程序
    printf("初始化失败");
    exit(0);
  }
  t.length=0;
  t.size=Size;
  return t;
}


/*
* 整个顺序表初始化的过程被封装到了一个函数中，此函数返回值是一个已经初始化完成的顺序表。
* 在主函数中调用该函数就可以创建一个空的顺序表
*/
//输出顺序表中元素
void displayTable(table t){
  for(int i=0;i<t.length;i++){
    printf("%d ",t.head[i]);
  }
  printf("\n");
}
int main(){
  table t=initTable();
  //向顺序表中添加元素
  for(int i=1;i<=Size;i++){
    t.head[i-1]=i;
    t.length++;
  }
  displayTable(t);
  return 0;
}