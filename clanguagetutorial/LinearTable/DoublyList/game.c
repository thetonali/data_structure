#include <stdio.h>
#include <stdbool.h>
#define ROW 10
#define COL 10

typedef struct SnakeNode{
    int x,y;
    struct SnakeNode*pre;
    struct SnakeNode*next;
}Node,*pNode;

//移动
//即链表中所有结点从尾节点开始逐个向前移动
bool Move(Node* head,Node*tail,char key){
    bool game_over=false;
    Node* tmp=tail;

    while(tmp!=head){
        tmp->x=tmp->pre->x;
        tmp->y=tmp->pre->y;
        tmp=tmp->pre;
    }

    switch(key){
        case'd':{
            head->x+=1;
            if(head->x>=ROW)
                game_over=true;
            break;
        }
        case'a':{
            head->x-=1;
            if(head->x<0)
                game_over=true;
            break;
        }
        case's':{
            head->y-=1;
            if(head->y<0)
                game_over=true;
            break;
        }
        case'w':{
            head->y+=1;
            if(head->y>=COL)
                game_over=true;
            break;
        }
    }

    if(SnakeDeath(head))
        game_over=true;
    return game_over;
}

typedef struct food{
    int x,y;
}Food,*pFood;

//吃食物
pNode EatFood(pNode head,pFood apple){
    Node* tmp=head;
    Node* newNode;
    if(apple->x==head->x && apple->y==head->y){
        newNode=(Node*)malloc(sizeof(Node));
        
    }
}