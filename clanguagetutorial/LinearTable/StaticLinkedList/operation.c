#include "initiate.h"
//向链表中插入数据，body表示链表的头节点在数组中的位置，add表示插入元素的位置，a表示要插入的元素
void insertArr(component*array,int body,int add,int a){
	int tempBody=body;//遍历数组用
	for(int i=1;i<add;i++){
		tempBody=array[body].next; //1.找到要插入的前一个位置
	}
	int insert=mallocArr(array);//2.申请空间，准备插入
	array[insert].data=a;
	array[insert].next=array[tempBody].next;
	array[tempBody].next=insert;

	//备用链表回收空间。k表示未使用节点的数组下标
void freeArr(component*array,int k){
	array[k].next=array[0].next;
	array[0].next=k;
}

//删除节点函数,a是被删除元素
void deletArr(component*array,int body,char a){
	int tempBody=body;
	//找到被删除节点的位置
	while(array[tempBody].data!=a){
		tempBody=array[tempBody].next;
		if(tempBody==0){
			printf("链表中没有此数据");
			return;
		}
	}
	int del=tempBody;
	tempBody=body;
	//找到该节点的上一个节点，删除
	while(array[tempBody].next!=del){
		tempBody=array[tempBody].next;
	}
	array[tempBody].next=array[del].next;
	freeArr(array,del);
}

//查找元素
int selectElem(component*array,int body,char elem){
	int tmpBody=body;
	while(array[tmpBody].next!=0){
		if(array[tmpBody].data==elem){
			return tmpBody;
		}
		tmpBody=array[tmpBody].next;
	}
	return -1;
}

//更改元素
void amendElem(component*array,int body,int oldElem,int newElem){
	int add=selectElem(array,body,oldElem);
	if(add==-1){
		printf("无更改元素");
		return;
	}
	array[add].data=newElem;
}

int main(){
	component array[maxSize];
	int body=initArr(array);
	printf("静态链表为：\n");
	displayArr(array,body);

	printf("在第3的位置上插入节点'e':\n");
	insertArr(array,body,3,'e');
	displayArr(array,body);

	printf("删除数据域为'a'的结点：\n");
	deletArr(array,body,'a');
	displayArr(array,body);

	printf("查找数据域为'e'的结点的位置：\n");
	int selectAdd=selectElem(array,body,'e');
	printf("%d\n",selectAdd);
	printf("将结点数据域为'e'改为'h':\n");
	amendElem(array,body,'e','h');
	displayArr(array,body);
	return 0;
}