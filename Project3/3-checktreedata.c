#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100

typedef struct TreeNode {
    int data;
    struct TreeNode* left, * right;
}TreeNode;

typedef TreeNode* element;
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
}QueueType;


void init_queue(QueueType* q) {

    q->front = q->rear = 0;
}

int is_empty(QueueType* q) {

    return (q->front == q->rear);
}

int is_full(QueueType* q) {

    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}


void enqueue(QueueType* q, element item) {
    if (is_full(q)) {
        printf("ť�� ��ȭ �����Դϴ�.\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element dequeue(QueueType* q) {
    if (is_empty(q)) {
        printf("ť�� ��������Դϴ�.\n");
        return NULL;
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}


void PlaceNode(TreeNode* root, int direction, int data) {
    if (direction == 0) {
        root->left = (TreeNode*)malloc(sizeof(TreeNode));
        root->left->data = data;
        root->left->left = NULL;
        root->left->right = NULL;
    }
    else if (direction == 1) {
        root->right = (TreeNode*)malloc(sizeof(TreeNode));
        root->right->data = data;
        root->right->left = NULL;
        root->right->right = NULL;
    }
}


void GenerateLinktree(TreeNode* root) {
    PlaceNode(root, 0, 2);
    PlaceNode(root, 1, 9);
    PlaceNode(root->left, 0, 3);
    PlaceNode(root->left, 1, 5);
    PlaceNode(root->right, 0, 10);
    PlaceNode(root->right, 1, 13);
    PlaceNode(root->left->left, 0, 4);
    PlaceNode(root->left->left, 1, 6);
    PlaceNode(root->left->right, 0, 7);
    PlaceNode(root->left->right, 1, 8);
    PlaceNode(root->right->left, 0, 11);
    PlaceNode(root->right->left, 1, 12);
    PlaceNode(root->right->right, 0, 14);
    PlaceNode(root->right->right, 1, 15);
}

int GetSumOfNodes(TreeNode* root) {
    int node_sum = 0;
    QueueType q;

    init_queue(&q);
    if (root == NULL) return 0;
    enqueue(&q, root);
    while (!is_empty(&q)) { 
        root = dequeue(&q);
        node_sum += root->data;
        //��ť�� ���� �ڽĵ��� ��ť�ϴ°�
        if (root->left)
            enqueue(&q, root->left);
        if (root->right)
            enqueue(&q, root->right);
    }
    return node_sum;

}



int GetNumberOfNodes(TreeNode* root) {
    int node_count = 0;

    QueueType q;

    init_queue(&q);
    if (root == NULL) return 0;
    enqueue(&q, root);
    while (!is_empty(&q)) {
        root = dequeue(&q);
        node_count++; // ��ť�� ��带 1�� ī��Ʈ���ִ°�

        // ��ť�� ����� �ڽĵ��� ��ť�ϴ°�
        if (root->left)
            enqueue(&q, root->left);
        if (root->right)
            enqueue(&q, root->right);
    }

    return node_count;


}


int GetHeightOfTree(TreeNode* root) {
    if (root == NULL) return 0;

    int height = 0;
    QueueType q;
    init_queue(&q);

    enqueue(&q, root);

    while (!is_empty(&q)) {
        int level_size = (q.rear - q.front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; //ť���� ���� ������ ��� ���� ����ϴ� �κ�!!! 
        
        // �� �������� ��� �������� ��ť�� ���ְ�, �� ��ť�� ����� ���ʰ� �������� ��ť���ִ� �κ�!!!  
        for (int i = 0; i < level_size; i++) {
            TreeNode* current = dequeue(&q);
            if (current->left)
                enqueue(&q, current->left);
            if (current->right)
                enqueue(&q, current->right);
        }
<<<<<<< HEAD
        // ���� �۾�(������ ���� ��ť���ְ� �� ��ť�� ��� ���ʰ� �������� ��ť�ϴ� �۾�)�� ��ġ�� ���� ���̸� 1�� ������Ų��!!!!!!! 
=======
        // ���� �۾�(������ ���� ��ť���ְ� �� ��ť�� ��� ���ʰ� �������� ��ť�ϴ� �۾�)�� ��ġ�� ���� ���̸� 1�� ������Ų��!!!! 
>>>>>>> a71aaa50d97148c4b5dd89d3320419aadd4a6b66
        height++;
    }

    return height;


}


int GetNumberOfLeafNodes(TreeNode* root)
{
    int leaf_node = 0;
    QueueType q;
    init_queue(&q);

    if (root == NULL) return 0;
    enqueue(&q, root);

    while (!is_empty(&q)) {
        root = dequeue(&q);

        //��ť�� ���� ���� �ڽİ� ������ �ڽ��� NULL�� ����ų ��� leaf_node�� ���� 1�� ������Ű�°�!!! 
        if (root->left == NULL && root->right == NULL) {
            leaf_node++;
        }

        // �ƴϸ� ��� ��ť�Ѱ��� ���� �ڽİ� ������ �ڽ��� ��ť���ش�.!!!
        else {
            if (root->left) {
                enqueue(&q, root->left);
            }

            if (root->right) {
                enqueue(&q, root->right);
            }


        }

    }
    return leaf_node;
}

int main() {
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->data = 1;


    GenerateLinktree(root);
    printf("Sum of nodes : %d\n", GetSumOfNodes(root));
    printf("Number of nodes:%d\n", GetNumberOfNodes(root));
    printf("Height of Tree: %d\n", GetHeightOfTree(root));
    printf("Number of leaf nodes:%d\n", GetNumberOfLeafNodes(root));


}