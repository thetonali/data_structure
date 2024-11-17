#include <stdio.h>
#define maxSize 6
typedef struct{
	int data;
	int next;
}component;

//���ṹ�����������з������ӵ���������
void reserveArr(component*array);
//��ʼ����̬����
int initArr(component*array);
//�������
void displayArr(component*array,int body);
//�ӱ���������ժ�¿��нڵ�ĺ���
int mallocArr(component*array);

// int main(){
// 	component array[maxSize];
// 	int body=initArr(array);
// 	printf("��̬����Ϊ��\n");
// 	displayArr(array,body);
// 	return 0;
// }
	
//������������
void reserveArr(component*array){
	for(int i=0;i<maxSize;i++){
		array[i].next=i+1;//��ÿ�����ַ������ӵ�һ��
		array[i].data=-1;
	}
	array[maxSize-1].next=0;//�������һ���ڵ���α�ֵΪ0
}

//��ȡ����ռ�
int mallocArr(component*array){
	//����������ǿգ��򷵻ط���Ľڵ��±ꣻ���򷵻�0�����������һ���ڵ�ʱ���ýڵ���α�ֵΪ0��
	int i=array[0].next;
	if(array[0].next){
		array[0].next=array[i].next;
	}
	return i;
}

//��ʼ����̬����
int initArr(component*array){
	reserveArr(array);
	int body=mallocArr(array);
	//����һ��������������ָ��ʹ��ָ�����������һ���ڵ㣬��Ϊ����Ϊ�գ�����ͷ�ڵ��غ�
	int tempBody=body;
	for(int i=0;i<4;i++){
		int j=mallocArr(array);//�ӱ����������ó����еķ���
		array[tempBody].next=j;//������Ŀ��з�����������������һ���ڵ����
		array[j].data=i;//��������ķ������������ʼ��
		tempBody=j;//��ָ���������һ���ڵ��ָ�����
	}
	array[tempBody].next=0;//�µ��������һ���ڵ��ָ������Ϊ0
	return body;
}

void displayArr(component*array,int body){
	int tempBody=body;//������ʹ��
	while(array[tempBody].next){
		printf("%d,%d ",array[tempBody].data,array[tempBody].next);
		tempBody=array[tempBody].next;
	}
	printf("%d,%d\n",array[tempBody].data,array[tempBody].next);
}	