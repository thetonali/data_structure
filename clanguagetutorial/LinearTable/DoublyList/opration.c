#include "initate.h"
//line就是node的意思

//插入
line* insertLine(line*head,int data,int pos){
    line*newNode=(line*)malloc(sizeof(line));
    newNode->data=data;
    newNode->next=NULL;
    newNode->prior=NULL;

    //!插入位置分情况讨论
    if(pos==1){
        newNode->next=head;
        head->prior=newNode;
        head=newNode;//注意更新head的位置！
    }
    else{
        line*tmp=head;
        for(int i=1;i<pos-1;i++){
            tmp=tmp->next;
        }
        if(tmp->next==NULL){
            tmp->next=newNode;
            newNode->prior=tmp;
        }
        else{
            newNode->next=tmp->next;
            newNode->prior=tmp;
            tmp->next->prior=newNode;
            tmp->next=newNode;
        }
    }
    return head;
}

//删除
line* delLine(line*head,int data){
    line*tmp=head;
    while(tmp){
        if(tmp->data==data){
            tmp->prior->next=tmp->next;
            tmp->next->prior=tmp->prior;
            free(tmp);
            return head; //找到了就释放，然后退出
        }
        tmp=tmp->next;
    }
    printf("链表中无该数据元素。");
    return head;
}

//查找结点
int searchElem(line*head,int elem){
    line*tmp=head;
    int index=1;
    while(tmp){
        if(tmp->data==elem)
            return index;
        tmp=tmp->next;
        index++;
    }
    return -1;
}

//更改结点
line*amendElem(line*head,int elem,int newElem){
    line*tmp=head;
    int index=searchElem(head,elem);

    for(int i=1;i<index;i++){
        tmp=tmp->next;
    }
    tmp->data=newElem;
    return head;
}


int main(){
    line*head=NULL;
    head=initLine(head);
    disply(head);

    insertLine(head,16,3);
    disply(head);

    delLine(head,3);
    disply(head);

    int pos=searchElem(head,16);
    printf("%d\n",pos);

    amendElem(head,4,33);
    disply(head);

    return 0;
}
