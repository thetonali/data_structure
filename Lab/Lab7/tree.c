#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//二叉树结点
typedef struct treeNode{
    char data;
    struct treeNode*left;
    struct treeNode*right;
}TreeNode,*Tree;

//队列结点(用于层序遍历)
typedef struct queueNode{
    TreeNode* treeNode;
    struct queueNode*next;
}QueueNode;

//队列
typedef struct queue{
    QueueNode* rear;
    QueueNode* front;
}Queue;

//创建新的二叉树结点
TreeNode* creatNode(char data){
    TreeNode* newNode=(TreeNode*)malloc(sizeof(TreeNode));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

//二叉树的先序创建(#代表空结点)
Tree creatTree(){
    char data;
    scanf("%c",&data);
    if(data=='#')
        return NULL;
    TreeNode* root=creatNode(data);
    root->left=creatTree();
    root->right=creatTree();
    return root;
}

//先序递归
void preRecursive(Tree root){
    if(root==NULL)
        return;
    printf("%c",root->data);
    preRecursive(root->left);
    preRecursive(root->right);
}

//先序非递归
void pre(Tree root){
    if(root==NULL)
        return;
    TreeNode* stack[100];
    int top=-1;

    stack[++top]=root;
    while(top>=0){
        TreeNode *node=stack[top--];
        printf("%c", node->data);
        if(node->right)
            stack[++top]=node->right;
        if(node->left)
            stack[++top]=node->left;
    }
}

//中序递归
void inRecursive(Tree root){
    if(root==NULL)
        return;
    inRecursive(root->left);
    printf("%c",root->data);
    inRecursive(root->right);
}

//中序非递归
void in(Tree root){
    if(root==NULL)
        return;
    TreeNode* stack[100];
    int top=-1;

    TreeNode* cur=root;
    while(cur||top>=0){
        while(cur){
            stack[++top]=cur;
            cur=cur->left;
        }
        cur=stack[top--];
        printf("%c",cur->data);
        cur=cur->right;
    }
}

//后序递归
void postRecursive(Tree root){
    if(root==NULL)
        return;
    postRecursive(root->left);
    postRecursive(root->right);
    printf("%c",root->data);
}

//后序非递归
void post(Tree root){
    if(root==NULL)
        return;
    TreeNode*stack[100];
    TreeNode*output[100];
    int top=-1,outTop=-1;
    stack[++top]=root;

    while(top>=0){
        TreeNode*cur=stack[top--];
        output[++outTop]=cur;

        if(cur->left)
            stack[++top]=cur->left;
        if(cur->right)
            stack[++top]=cur->right;
    }
    while(outTop>=0)
        printf("%c",output[outTop--]->data);
}

//层序遍历
//入队
void enqueue(Queue*queue,TreeNode *node){
    QueueNode*newNode=(QueueNode*)malloc(sizeof(QueueNode));
    newNode->treeNode=node;
    newNode->next=NULL;
    if(queue->rear){//队列非空
        queue->rear->next=newNode;
    }
    else
        queue->front=newNode;
    queue->rear=newNode; //更新
}

//出队
TreeNode*dequeue(Queue *queue) {
    if(queue->front==NULL)
        return NULL;
    QueueNode* qNode=queue->front;
    TreeNode* Tnode=queue->front->treeNode;
    queue->front=qNode->next;
    if(queue->front==NULL)
        queue->rear=NULL;
    free(qNode);
    return Tnode;
}


//层序遍历
void levelOrder(TreeNode*root) {
    if(root==NULL)
        return;
    Queue q={NULL,NULL};
    enqueue(&q,root);
    while(q.front!=NULL){
        TreeNode*cur=dequeue(&q);
        printf("%c",cur->data);
        if(cur->left)
            enqueue(&q,cur->left);
        if(cur->right)
            enqueue(&q,cur->right);
    }
}

//计算树的高度
int height(Tree root){
    if(root==NULL)
        return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    return (lh>=rh?lh:rh)+1;
}

void freeTree(Tree root){
    if(root==NULL)
        return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(){
    Tree root=creatTree();
    
    printf("先序遍历:  递归:\t");
    preRecursive(root);
    printf("\n           非递归:\t");
    pre(root);
    
    printf("\n中序遍历:  递归:\t");
    inRecursive(root);
    printf("\n           非递归:\t");
    in(root);

    printf("\n后序遍历:  递归:\t");
    postRecursive(root);
    printf("\n           非递归:\t");
    post(root);

    printf("\n层序遍历:       \t");
    levelOrder(root);

    printf("\n树高:           \t");
    printf("%d\n",height(root));

    freeTree(root);
    return 0;
}



