#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

typedef struct node{
    int left;
    int right;
}Node;

int findRoot(int n,Node nodes[]);
void printLeaf(int root,Node nodes[]);

int main() {
    int n;
    Node nodes[N];
    int isChild[N] = {0}; // 用于判断结点是否是某个结点的孩子

    // 输入结点总数
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char left[N], right[N];
        scanf("%s %s", left, right);

        if (strcmp(left, "-") == 0) {
            nodes[i].left = -1;
        } else {
            nodes[i].left = atoi(left);
            isChild[nodes[i].left] = 1; // 标记为子结点
        }

        if (strcmp(right, "-") == 0) {
            nodes[i].right = -1;
        } else {
            nodes[i].right = atoi(right);
            isChild[nodes[i].right] = 1; // 标记为子结点
        }
    }

    // 找到根结点
    int root = findRoot(n, nodes);

    // 输出叶子结点
    printLeaf(root, nodes);

    return 0;
}

int findRoot(int n,Node nodes[]) {
    int isChild[N] = {0};

    for (int i = 0; i < n; i++) {
        if (nodes[i].left != -1) isChild[nodes[i].left] = 1;
        if (nodes[i].right != -1) isChild[nodes[i].right] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (!isChild[i]) {
            return i; // 找到根结点
        }
    }
    return -1; // 如果找不到根结点
}

void printLeaf(int root,Node nodes[]) {
    int queue[N];
    int front = 0, rear = 0;

    // 初始化队列
    queue[rear++] = root;

    int isFirst = 1;
    while (front < rear) {
        int current = queue[front++];

        // 如果是叶结点
        if (nodes[current].left == -1 && nodes[current].right == -1) {
            if (!isFirst) {
                printf(" ");
            }
            printf("%d", current);
            isFirst = 0;
        }

        // 添加左孩子
        if (nodes[current].left != -1) {
            queue[rear++] = nodes[current].left;
        }

        // 添加右孩子
        if (nodes[current].right != -1) {
            queue[rear++] = nodes[current].right;
        }
    }
    printf("\n");
}
