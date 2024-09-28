//#include <stdio.h>
//#include <stdlib.h>
//#define SIZE 20
//
//typedef struct TreeNode {
//    int data;
//    struct TreeNode* left, * right;
//} TreeNode;
//
//int top = -1;
//TreeNode* stack[SIZE];
//
//
//void push(TreeNode* node) {
//    if (top < SIZE - 1) {
//        stack[++top] = node;
//        printf("push(%2d) ", stack[top]->data);
//    }
//    else {
//        printf("Stack is full\n");
//    }
//}
//
//
//TreeNode* pop() {
//    if (top >= 0) {
//        printf("pop(%2d) ", stack[top]->data);
//        return stack[top--];
//    }
//    else {
//        printf("Stack is empty\n");
//        return NULL;
//    }
//}
//
//
//TreeNode* peek() {
//    if (top >= 0) {
//        return stack[top];
//    }
//    return NULL;
//}
//
//
//void PlaceNode(TreeNode* root, int direction, int data) {
//    if (direction == 0) {
//        root->left = malloc(sizeof(TreeNode));
//        root->left->data = data;
//        root->left->left = NULL;
//        root->left->right = NULL;
//    }
//    else if (direction == 1) {
//        root->right = malloc(sizeof(TreeNode));
//        root->right->data = data;
//        root->right->left = NULL;
//        root->right->right = NULL;
//    }
//}
//
//
//void GenerateLinkTree(TreeNode* root) {
//    PlaceNode(root, 0, 2);
//    PlaceNode(root, 1, 9);
//    PlaceNode(root->left, 0, 3);
//    PlaceNode(root->left, 1, 5);
//    PlaceNode(root->right, 0, 10);
//    PlaceNode(root->right, 1, 13);
//    PlaceNode(root->left->left, 0, 4);
//    PlaceNode(root->left->left, 1, 6);
//    PlaceNode(root->left->right, 0, 7);
//    PlaceNode(root->left->right, 1, 8);
//    PlaceNode(root->right->left, 0, 11);
//    PlaceNode(root->right->left, 1, 12);
//    PlaceNode(root->right->right, 0, 14);
//    PlaceNode(root->right->right, 1, 15);
//}
//
//// 링크 트리구조에서 스택을 이용해서 푸쉬하고 팝을 통해 (전위순회로) 출력하는 함수   
//void LinkePreOrder(TreeNode* root) {
//    if (root == NULL) return;
//
//    push(root); // 루트 노드를  푸쉬한다.
//    while (top >= 0) { // 스택의 탑이 0이 될때까지 반복 
//        TreeNode* del = pop();      // del 노드를 팝한다. 
//        if (del != NULL) {
//            printf("visit(%2d)\n", del->data);  // del 노드 데이터 출력 
//
//            // 스택은 LIFO구조이기 때문에 오른쪽부터 푸쉬를 하면 오른쪽의 값은 나중에 빠져 나오기 때문에 오른쪽부터 푸쉬하는게 맞음!! 
//
//            if (del->right != NULL) {      // del->right로 이동하고 푸쉬한다.
//                push(del->right);
//            }
//
//            if (del->left != NULL) {    //del->left로 이동하고 푸쉬한다.
//                push(del->left);
//            }
//
//        }
//    }
//}
//
//// 링크 트리구조에서 스택을 이용해서 푸쉬하고 팝을 통해 (중위순회로) 출력하는 함수  
//void LinkInOrder(TreeNode* root) {
//    if (root == NULL) return;
//
//    TreeNode* current = root;
//    while (current != NULL || top >= 0) {// current가 NULL아니거나 top이 0보다 작다면 계속 반복한다!!! 
//        while (current != NULL) { // current가 NULL이 아닐때까지  current 노드를 푸시하고 왼쪽으로 이동을 반복 
//            push(current);  
//            current = current->left; 
//        }
//        current = pop(); // 계속 왼쪽으로 가는 while 문에서 나와서 마지막에 팝했던 노드(부모노드)로 돌아가는곳!!!! 
//        printf("visit(%2d)\n", current->data); //팝한 current 노드 데이터를 출력한다.
//
//        current = current->right;   // current를 오른쪽으로 이동
//    }
//}
//
//
//// 링크 트리구조에서 스택을 이용해서 푸쉬하고 팝을 통해 (후위순회로) 출력하는 함수  
//void LinkPostOrder(TreeNode* root) {
//    if (root == NULL) return;
//
//    TreeNode* current = root;
//    TreeNode* lastVisited = NULL;
//    while (top >= 0 || current != NULL) {
//        //current가 NULL이 아니면 계속 왼쪽으로 이동하고 푸쉬하는 곳
//        if (current != NULL) {
//            push(current);
//            current = current->left;
//        }
//        else { // current가 NULL일 경우 실행되는 곳
//            TreeNode* peekNode = peek(); // 현재 스택의 탑을 가지고 오는곳(부모 노드로 돌아가는곳)
//
//            if (peekNode->right != NULL && lastVisited != peekNode->right) { //peekNode의 오른쪽 자식이 NULL이거나, 이미 방문한 노드(lastVisited)가 아니라면 오른쪽으로 이동한다.!!
//                current = peekNode->right;
//            }
//            else {
//                pop();
//                printf("visit(%2d)\n", peekNode->data); // pop()으로 노드를 스택에서 제거하기 전에 그 노드의 포인터를
//                                                        //peekNode에 저장하기 때문에 pop한 데이터를 출력할 수 있는것이다.!!! 
//                lastVisited = peekNode;
//            }
//        }
//    }
//}
//
//
//void FreeTree(TreeNode* root) {
//    if (root != NULL) {
//        FreeTree(root->left);
//        FreeTree(root->right);
//        free(root);
//    }
//}
//
//
//void LinkOrders(TreeNode* root) {
//    LinkePreOrder(root);
//    printf("\n\n");
//    LinkInOrder(root);
//    printf("\n\n");
//    LinkPostOrder(root);
//    printf("\n\n");
//
//
//}
//
//int main() {
//    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
//    root->data = 1;
//    root->left = NULL;
//    root->right = NULL;
//
//    GenerateLinkTree(root);
//    LinkOrders(root);
//
//    FreeTree(root);
//
//    return 0;
//}