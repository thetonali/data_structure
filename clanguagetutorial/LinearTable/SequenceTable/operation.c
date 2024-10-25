#include "public.h"

/*
* 顺序表插入元素
  1.表头
  2.中间位置
  3.最后一个位置
* 通过遍历，找到要插入的位置
  1.将要插入位置的元素及后续元素整体向后移动一个位置
  2.将元素放在腾出来的位置*/
//* 插入函数
table addTable(table t,int elem,int add){
  //判断插入本身是否存在问题（插入位置）
  if(add>t.length+1||add<1){
    printf("插入位置有问题\n");
    return t;
  }

  //先看顺序表有无空余位置，没有就申请
  if(t.length==t.size){
    //动态数组额外申请更多物理空间使用的是 realloc 函数
    t.head=(int*)realloc(t.head,(t.size+1)*sizeof(int));
    if(t.head==NULL){
      printf("存储分配失败\n");
      return t;
    }
    t.size+=1;
  }

  //插入操作——要从后往前移动
  for(int i=t.length-1;i>=add-1;i--){
    t.head[i+1]=t.head[i];
  }
  //后移完成，添加元素
  t.head[add-1]=elem;
  t.length++;
  return t;
}


/*
* 顺序表删除元素
  1.找到目标元素
  2.将后续元素整体前移1个位置*/
//* 删除函数
table delTable(table t,int add){
  if(add>t.length||add<1){
    printf("被删除元素的位置有误\n");
    return t;
  }
  //删除操作
  for(int i=add-1;i<t.length-1;i++){
    t.head[i]=t.head[i+1];
  }
  t.length--;
  return t;
}

/*
* 顺序表查找元素
  1.二分查找
  2.顺序查找*/
//* 顺序查找函数
int selectTable(table t,int elem){
  for(int i=0;i<t.length;i++){
    if(t.head[i]==elem){
      return i+1;
    }
  }
  return -1;
}

/*
* 顺序表更改元素
  1.找到目标元素
  2.直接修改*/
//* 更改函数
table amendTable(table t,int elem,int newElem){
  int add=selectTable(t,elem);
  t.head[add-1]=newElem;
  return t;
}

int main(){
  table t=initTable();
  for(int i=1;i<=Size;i++){
    t.head[i-1]=i;
    t.length++;
  }
  printf("原顺序表:\n");
  displayTable(t);

  printf("删除元素1:\n");
  t=delTable(t,1);
  displayTable(t);

  printf("在第2的位置插入元素5:\n");
  t=addTable(t,5,2);
  displayTable(t);

  printf("查找元素3的位置:\n");
  int add=selectTable(t,3);
  printf("%d\n",add);

  printf("将元素3改为6:\n");
  t=amendTable(t,3,6);
  displayTable(t);

  return 0;
}