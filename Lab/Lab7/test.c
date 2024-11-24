#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 二叉树节点定义
typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// 队列节点定义（用于层序遍历）
typedef struct QueueNode {
    TreeNode *treeNode;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue {
    QueueNode *front;
    QueueNode *rear;
} Queue;

// 创建新的二叉树节点
TreeNode* createNode(int data) {
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 二叉树的先序创建（输入 -1 表示空节点）
TreeNode* createTree() {
    int data;
    scanf("%d", &data);
    if (data == -1) {
        return NULL;
    }
    TreeNode *root = createNode(data);
    root->left = createTree();
    root->right = createTree();
    return root;
}

// 递归遍历
void preorderRecursive(TreeNode *root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorderRecursive(root->left);
    preorderRecursive(root->right);
}

void inorderRecursive(TreeNode *root) {
    if (root == NULL) return;
    inorderRecursive(root->left);
    printf("%d ", root->data);
    inorderRecursive(root->right);
}

void postorderRecursive(TreeNode *root) {
    if (root == NULL) return;
    postorderRecursive(root->left);
    postorderRecursive(root->right);
    printf("%d ", root->data);
}

// 非递归遍历
void preorderNonRecursive(TreeNode *root) {
    if (root == NULL) return;
    TreeNode *stack[100];
    int top = -1;
    stack[++top] = root;
    while (top >= 0) {
        TreeNode *node = stack[top--];
        printf("%d ", node->data);
        if (node->right) stack[++top] = node->right;
        if (node->left) stack[++top] = node->left;
    }
}

void inorderNonRecursive(TreeNode *root) {
    if (root == NULL) return;
    TreeNode *stack[100];
    int top = -1;
    TreeNode *curr = root;
    while (curr || top >= 0) {
        while (curr) {
            stack[++top] = curr;
            curr = curr->left;
        }
        curr = stack[top--];
        printf("%d", curr->data);
        curr = curr->right;
    }
}

void postorderNonRecursive(TreeNode *root) {
    if (root == NULL) return;
    TreeNode *stack[100];
    TreeNode *output[100];
    int top = -1, outTop = -1;
    stack[++top] = root;
    while (top >= 0) {
        TreeNode *node = stack[top--];
        output[++outTop] = node;
        if (node->left) stack[++top] = node->left;
        if (node->right) stack[++top] = node->right;
    }
    while (outTop >= 0) {
        printf("%d ", output[outTop--]->data);
    }
}

// 层序遍历
void enqueue(Queue *queue, TreeNode *node) {
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    newNode->treeNode = node;
    newNode->next = NULL;
    if (queue->rear) {
        queue->rear->next = newNode;
    } else {
        queue->front = newNode;
    }
    queue->rear = newNode;
}

TreeNode* dequeue(Queue *queue) {
    if (!queue->front) return NULL;
    QueueNode *temp = queue->front;
    TreeNode *node = temp->treeNode;
    queue->front = temp->next;
    if (!queue->front) queue->rear = NULL;
    free(temp);
    return node;
}

bool isQueueEmpty(Queue *queue) {
    return queue->front == NULL;
}

void levelOrderTraversal(TreeNode *root) {
    if (root == NULL) return;
    Queue queue = {NULL, NULL};
    enqueue(&queue, root);
    while (!isQueueEmpty(&queue)) {
        TreeNode *node = dequeue(&queue);
        printf("%d ", node->data);
        if (node->left) enqueue(&queue, node->left);
        if (node->right) enqueue(&queue, node->right);
    }
}

// 计算二叉树的高度
int treeHeight(TreeNode *root) {
    if (root == NULL) return 0;
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// 主函数
int main() {
    TreeNode *root = createTree();
    
    printf("递归遍历结果：\n");
    printf("先序遍历：");
    preorderRecursive(root);
    printf("\n中序遍历：");
    inorderRecursive(root);
    printf("\n后序遍历：");
    postorderRecursive(root);
    printf("\n");
    
    printf("非递归遍历结果：\n");
    printf("先序遍历：");
    preorderNonRecursive(root);
    printf("\n中序遍历：");
    inorderNonRecursive(root);
    printf("\n后序遍历：");
    postorderNonRecursive(root);
    printf("\n");
    
    printf("层序遍历：");
    levelOrderTraversal(root);
    printf("\n");
    
    printf("二叉树的高度：%d\n", treeHeight(root));
    
    return 0;
}
