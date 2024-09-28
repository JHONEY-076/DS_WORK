//
//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAX_SIZE 15
//
//
//// 트리 노드의 구조체
//typedef struct TreeNode {
//    int data;
//    struct TreeNode* left, * right;
//}TreeNode;
//
//// 트리노드의 순서대로 배열에 담아주는 함수
//void GenerateArrayTree(int* tree) {
//
//    int list[15] = { 1, 2, 9, 3, 5, 10, 13, 4, 6, 7, 8, 11, 12, 14, 15 };
//
//    for (int i = 0; i < 15; i++) {
//        tree[i] = list[i];
//    }
//
//    for (int i = 0; i < 15; i++) {
//        printf(" %2d", tree[i]);
//    }
//    printf("\n\n");
//}
//
//// 트리 노드의 순서대로 담아진 배열에서 전위 순회로 출력하는 함수
//void ArrayPreOrder(int* tree, int index) {
//    if (index < MAX_SIZE && tree[index] != -1) {
//        printf(" %2d", tree[index]);
//        ArrayPreOrder(tree, 2 * index + 1);
//        ArrayPreOrder(tree, 2 * index + 2);
//    }
//}
//
//
//// 트리 노드의 순서대로 담아진 배열에서 중위 순회로 출력하는 함수
//void ArrayInorder(int* tree, int index) {
//    if (index < MAX_SIZE && tree[index] != -1) {
//        ArrayInorder(tree, 2 * index + 1);
//        printf(" %2d", tree[index]);
//        ArrayInorder(tree, 2 * index + 2);
//    }
//}
//
//// 트리 노드의 순서대로 담아진 배열에서 후위 순회로 출력하는 함수
//void ArrayPostOrder(int* tree, int index) {
//    if (index < MAX_SIZE && tree[index] != -1) {
//        ArrayPostOrder(tree, 2 * index + 1);
//        ArrayPostOrder(tree, 2 * index + 2);
//        printf(" %2d", tree[index]);
//    }
//}
//
//
//// 배열을 이용한 전위, 중위, 후위 순회 방법으로 호출하는 함수
//void ArrayOrders(int* tree) {
//
//    ArrayPreOrder(tree, 0);
//    printf("\n");
//
//
//    ArrayInorder(tree, 0);
//    printf("\n");
//
//
//    ArrayPostOrder(tree, 0);
//    printf("\n");
//    printf("\n");
//}
//
//// 루트의 방향에 따라서 노드를 만들고 데이터를 삽입하여 링크 표현법을 통해 트리를 만드는 함수
//void PlaceNode(TreeNode* root, int direction, int data)
//{
//    if (direction == 0) {
//        root->left = malloc(sizeof(TreeNode));
//        root->left->data = data;
//        root->left->left = NULL;
//        root->left->right = NULL;
//    }
//    else if (direction == 1) {
//        root->right = malloc(sizeof(TreeNode));
//        root->right->data = data;
//        root->right->right = NULL;
//        root->right->left = NULL;
//    }
//
//}
//
//// PlaceNode를 호출하기 위해 방향과 노드의 데이터를 보내주는 함수
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
//// 링크 표현법으로 만들어진 트리를 전위순회로 출력하는 함수
//void LinkePreOrder(TreeNode* tree) {
//    if (tree != NULL) {
//        printf(" %2d", tree->data);
//        LinkePreOrder(tree->left);
//        LinkePreOrder(tree->right);
//    }
//}
//// 링크 표현법으로 만들어진 트리를 중위순회로 출력하는 함수
//void LinkInOrder(TreeNode* tree) {
//    if (tree != NULL) {
//
//        LinkInOrder(tree->left);
//        printf(" %2d", tree->data);
//        LinkInOrder(tree->right);
//    }
//}
//
//// 링크 표현법으로 만들어진 트리를 후위순회를 통해 출력하는 함수
//void LinkPostOrder(TreeNode* tree) {
//    if (tree != NULL) {
//
//        LinkPostOrder(tree->left);
//
//        LinkPostOrder(tree->right);
//
//        printf(" %2d", tree->data);
//
//
//    }
//
//}
//// 링크 표현법으로 전위, 중위, 후위로 출력하는 함수를 호출하는 함수
//void LinkOrders(TreeNode* root) {
//    LinkePreOrder(root);
//    printf("\n");
//    LinkInOrder(root);
//    printf("\n");
//    LinkPostOrder(root);
//    printf("\n");
//
//}
//
//
//
//int main() {
//    int arr[MAX_SIZE];
//    TreeNode* root = malloc(sizeof(TreeNode));  // 루트 노드 생성 
//    root->data = 1; //루트 노드에 1을 삽입
//
//    GenerateArrayTree(arr); // 배열 표현법으로 만들어낸 트리 
//    GenerateLinkTree(root); // 링크 표현법으로 만들어낸 트리
//
//
//
//    ArrayOrders(arr);       // 배열 표현법으로 만들어낸 트리에서 전위 중위 후위 순회를 출력
//    LinkOrders(root);       // 링크 표현법으로 만들어낸 트리에서 전위 중위 후위 순회를 출력
//
//    return 0;
//}
