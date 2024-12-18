#include <stdio.h>
#define maxSize 6
typedef struct{
	int data;
	int next;
}component;

//将结构体数组中所有分量链接到备用链表
void reserveArr(component*array);
//初始化静态链表
int initArr(component*array);
//输出函数
void displayArr(component*array,int body);
//从备用链表上摘下空闲节点的函数
int mallocArr(component*array);

// int main(){
// 	component array[maxSize];
// 	int body=initArr(array);
// 	printf("静态链表为：\n");
// 	displayArr(array,body);
// 	return 0;
// 	}
	
//创建备用链表
void reserveArr(component*array){
	for(int i=0;i<maxSize;i++){
		array[i].next=i+1;//将每个数字分量链接到一起
		array[i].data=-1;
	}
	array[maxSize-1].next=0;//链表最后一个节点的游标值为0
}

//提取分配空间
int mallocArr(component*array){
	//若备用链表非空，则返回分配的节点下标；否则返回0（当分配最后一个节点时，该节点的游标值为0）
	int i=array[0].next;
	if(array[0].next){
		array[0].next=array[i].next;
	}
	return i;
}

//初始化静态链表
int initArr(component*array){
	reserveArr(array);
	int body=mallocArr(array);
	//声明一个变量，把它当指针使，指向链表的最后的一个节点，因为链表为空，所以头节点重合
	int tempBody=body;
	for(int i=0;i<4;i++){
		int j=mallocArr(array);//从备用链表中拿出空闲的分量
		array[tempBody].next=j;//将申请的空闲分量链接在链表的最后一个节点后面
		array[j].data=i;//给新申请的分量的数据域初始化
		tempBody=j;//将指向链表最后一个节点的指针后移
	}
	array[tempBody].next=0;//新的链表最后一个节点的指针设置为0
	return body;
}

void displayArr(component*array,int body){
	int tempBody=body;//做遍历使用
	while(array[tempBody].next){
		printf("%d,%d ",array[tempBody].data,array[tempBody].next);
		tempBody=array[tempBody].next;
	}
	printf("%d,%d\n",array[tempBody].data,array[tempBody].next);
}	