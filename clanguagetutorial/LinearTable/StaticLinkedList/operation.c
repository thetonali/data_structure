#include "initiate.h"
//�������в������ݣ�body��ʾ�����ͷ�ڵ��������е�λ�ã�add��ʾ����Ԫ�ص�λ�ã�a��ʾҪ�����Ԫ��
void insertArr(component*array,int body,int add,int a){
	int tempBody=body;//����������
	for(int i=1;i<add;i++){
		tempBody=array[body].next; //1.�ҵ�Ҫ�����ǰһ��λ��
	}
	int insert=mallocArr(array);//2.����ռ䣬׼������
	array[insert].data=a;
	array[insert].next=array[tempBody].next;
	array[tempBody].next=insert;

	//����������տռ䡣k��ʾδʹ�ýڵ�������±�
void freeArr(component*array,int k){
	array[k].next=array[0].next;
	array[0].next=k;
}

//ɾ���ڵ㺯��,a�Ǳ�ɾ��Ԫ��
void deletArr(component*array,int body,char a){
	int tempBody=body;
	//�ҵ���ɾ���ڵ��λ��
	while(array[tempBody].data!=a){
		tempBody=array[tempBody].next;
		if(tempBody==0){
			printf("������û�д�����");
			return;
		}
	}
	int del=tempBody;
	tempBody=body;
	//�ҵ��ýڵ����һ���ڵ㣬ɾ��
	while(array[tempBody].next!=del){
		tempBody=array[tempBody].next;
	}
	array[tempBody].next=array[del].next;
	freeArr(array,del);
}

//����Ԫ��
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

//����Ԫ��
void amendElem(component*array,int body,int oldElem,int newElem){
	int add=selectElem(array,body,oldElem);
	if(add==-1){
		printf("�޸���Ԫ��");
		return;
	}
	array[add].data=newElem;
}

int main(){
	component array[maxSize];
	int body=initArr(array);
	printf("��̬����Ϊ��\n");
	displayArr(array,body);

	printf("�ڵ�3��λ���ϲ���ڵ�'e':\n");
	insertArr(array,body,3,'e');
	displayArr(array,body);

	printf("ɾ��������Ϊ'a'�Ľ�㣺\n");
	deletArr(array,body,'a');
	displayArr(array,body);

	printf("����������Ϊ'e'�Ľ���λ�ã�\n");
	int selectAdd=selectElem(array,body,'e');
	printf("%d\n",selectAdd);
	printf("�����������Ϊ'e'��Ϊ'h':\n");
	amendElem(array,body,'e','h');
	displayArr(array,body);
	return 0;
}