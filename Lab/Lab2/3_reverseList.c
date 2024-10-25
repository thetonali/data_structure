#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
typedef struct lnode {
    int data;
    struct lnode* next;
} Lnode, *LinkList;

// 创建链表并插入数据
LinkList createList(int n) {
    Lnode *p = (Lnode*)malloc(sizeof(Lnode));
    p->next = NULL;
    Lnode *temp = p;
    
    // 插入数据
    for (int i = 1; i <= n; i++) {
        int elem;
        scanf("%d", &elem);
        Lnode *newnode = (Lnode*)malloc(sizeof(Lnode));
        newnode->data = elem;
        newnode->next = NULL;
        temp->next = newnode;
        temp = newnode;
    }
    
    return p;  // 返回头节点
}

// 倒置链表
LinkList reverseList(LinkList head) {
    Lnode *prev = NULL, *curr = head->next, *next = NULL;
    
    while (curr != NULL) {
        next = curr->next;   // 保存下一个节点
        curr->next = prev;   // 当前节点指向前一个节点
        prev = curr;         // 前移 prev
        curr = next;         // 前移 curr
    }
    
    head->next = prev;  // 将头节点指向新的头节点
    return head;
}

// 打印链表
void printList(LinkList head) {
    Lnode *temp = head->next;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n;
    scanf("%d", &n);  // 输入链表节点个数
    
    // 创建链表
    LinkList list = createList(n);
    
    // 倒置链表
    list = reverseList(list);
    
    // 打印倒置后的链表
    printList(list);
    
    // 释放内存
    Lnode *cur = list;
    while (cur != NULL) {
        Lnode *next = cur->next;
        free(cur);
        cur = next;
    }

    return 0;
}
