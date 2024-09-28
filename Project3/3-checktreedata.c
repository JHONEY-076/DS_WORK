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
        printf("큐가 포화 상태입니다.\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element dequeue(QueueType* q) {
    if (is_empty(q)) {
        printf("큐가 공백상태입니다.\n");
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
        //디큐한 곳의 자식들을 인큐하는곳
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
        node_count++; // 디큐한 노드를 1씩 카운트해주는곳

        // 디큐한 노드의 자식들을 인큐하는곳
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
        int level_size = (q.rear - q.front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; //큐에서 현재 레벨의 노드 수를 계산하는 부분!!! 
        
        // 각 레벨들의 노드 수에따라 디큐를 해주고, 그 디큐한 노드의 왼쪽과 오른쪽을 인큐해주는 부분!!!  
        for (int i = 0; i < level_size; i++) {
            TreeNode* current = dequeue(&q);
            if (current->left)
                enqueue(&q, current->left);
            if (current->right)
                enqueue(&q, current->right);
        }
<<<<<<< HEAD
        // 위의 작업(노드수에 따라 디큐해주고 그 디큐한 노듸 왼쪽과 오른쪽을 인큐하는 작업)을 마치고 나서 높이를 1씩 증가시킨다!!!!!!! 
=======
        // 위의 작업(노드수에 따라 디큐해주고 그 디큐한 노듸 왼쪽과 오른쪽을 인큐하는 작업)을 마치고 나서 높이를 1씩 증가시킨다!!!! 
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

        //디큐한 곳의 왼쪽 자식과 오른쪽 자식이 NULL을 가리킬 경우 leaf_node의 값을 1씩 증가시키는곳!!! 
        if (root->left == NULL && root->right == NULL) {
            leaf_node++;
        }

        // 아니면 계속 디큐한곳의 왼쪽 자식과 오른쪽 자식을 인큐해준다.!!!
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