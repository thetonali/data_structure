#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
typedef struct lnode{
    int data;
    struct lnode* next;
} Lnode, *LinkList;

// 插入元素 k 到链表的合适位置
void insertNode(LinkList p, int k) {
    Lnode *cur = p;
    while (cur->next != NULL && cur->next->data < k) {
        cur = cur->next;
    }
    // 创建并插入新节点
    Lnode *key = (Lnode*)malloc(sizeof(Lnode));
    key->data = k;
    key->next = cur->next;
    cur->next = key;
}

int main() {
    int n, k;
    scanf("%d", &n);  // 输入链表节点个数

    // 初始化头节点
    Lnode *p = (Lnode*)malloc(sizeof(Lnode));
    p->next = NULL;
    Lnode *temp = p;

    // 读入链表数据
    for (int i = 1; i <= n; i++) {
        int elem;
        scanf("%d", &elem);
        Lnode *newnode = (Lnode*)malloc(sizeof(Lnode));
        newnode->data = elem;
        newnode->next = NULL;
        temp->next = newnode;
        temp = newnode;
    }

    // 输入待插入的值
    scanf("%d", &k);

    // 插入新节点到链表中
    insertNode(p, k);

    // 打印链表
    Lnode *tar = p->next;
    while (tar != NULL) {
        printf(" %d", tar->data);
        tar = tar->next;
    }

    // 释放内存
    Lnode *cur = p;
    while (cur != NULL) {
        Lnode *next = cur->next;
        free(cur);
        cur = next;
    }

    return 0;
}
