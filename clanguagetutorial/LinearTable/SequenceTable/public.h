#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define Size 5
/*
* 顺序表（顺序存储结构），是线性表的一种。
* 顺序表存储数据：提前申请一整块足够大小的物理空间，将数据一次存储起来*/

/* 
  1.存储容量
  2.长度（表中存储数据元素的个数）*/
typedef struct Table{
    int*head; //声明的一个未初始化的动态数组，不要看做普通的指针
    int length;
    int size;
}table;

table initTable(){
  table t;
  t.head=(int*)malloc(Size*sizeof(int));
  if(!t.head){
    printf("初始化失败");
    exit(0);
  }
  t.length=0;
  t.size=Size;
  return t;
}

void displayTable(table t){
  for(int i=0;i<t.length;i++){
    printf("%d ",t.head[i]);
  }
  printf("\n");
}
