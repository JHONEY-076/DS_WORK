//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct TreeNode {
//    int data;
//    struct TreeNode* left, * right;
//    int is_thread; // 스레드 여부를 나타내는 변수
//} TreeNode;
//
//// 함수 프로토타입 선언
//void setInorderThreads(TreeNode* root);
//
//void PlaceNode(TreeNode* root, int direction, int data) {
//    TreeNode* newNode = malloc(sizeof(TreeNode));
//    newNode->data = data;
//    newNode->left = NULL;
//    newNode->right = NULL;
//    newNode->is_thread = 0; // 스레드 아님을 표시
//
//    if (direction == 0) {
//        root->left = newNode;
//    }
//    else if (direction == 1) {
//        root->right = newNode;
//    }
//}
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
//
//
//
//   
//
//}
//
//void setInorderThreads(TreeNode* root) {
//    if (root == NULL) return;
//
//    // 스레드 설정
//    root->left->left->left->is_thread = 1; // 4가 스레드임을 표시
//    root->left->left->left->right = root->left->left; // 4의 스레드 포인터가 3을 가리킴
//
//    root->left->left->right->is_thread = 1; // 6이 스레드임을 표시
//    root->left->left->right->right = root->left; // 6의 스레드 포인터가 2을 가리킴
//
//    root->left->right->left->is_thread = 1; // 5의 스레드 설정
//    root->left->right->left->right = root->left->right; // 7의 스레드 포인터가 5를 가리킴
//
//    root->left->right->right->is_thread = 1; // 8이 스레드임을 표시
//    root->left->right->right->right = root; // 8의 스레드 포인터가 1을 가리킴
//
//    root->right->left->left->is_thread = 1; // 11의 오른쪽 스레드를 10으로 설정
//    root->right->left->left->right = root->right->left; // 11의 스레드 포인터가 10을 가리킴
//
//    root->right->left->right->is_thread = 1; // 12가 스레드임을 표시
//    root->right->left->right->right = root->right; // 12의 스레드 포인터가 9을 가리킴
//
//    root->right->right->left->is_thread = 1; // 14가 스레드임을 표시
//    root->right->right->left->right = root->right->right; // 14의 스레드 포인터가 13을 가리킴
//}
//
//void setPreorderThreads(TreeNode* root) {
//
//    root->left->left->left->is_thread = 1;
//    root->left->left->left->right = root->left->left->right;
//
//    root->left->left->right->is_thread = 1;
//    root->left->left->right->right = root->left->right;
//
//    root->left->right->left->is_thread = 1;
//    root->left->right->left->right = root->left->right->right;
//
//    root->left->right->right->is_thread = 1;
//    root->left->right->right->right = root->right;
//
//    root->right->left->left->is_thread = 1;
//    root->right->left->left->right = root->right->left->right;
//
//    root->right->left->right->is_thread = 1;
//    root->right->left->right->right = root->right->right;
//
//    root->right->right->left->is_thread = 1;
//    root->right->right->left->right = root->right->right->right;
//
//
//
//}
//
//
//void setPostorderThreads(TreeNode* root) {
//    
//    root->left->left->left->is_thread = 1;
//    root->left->left->left->right = root->left->left->left->right;
//
//    root->left->left->left->right->is_thread = 1;
//    root->left->left->left->right->right = root->left->left;
//
//    root->left->left->is_thread = 1;
//    root->left->left->right = root->left->right->left;
//
//    root->left->right->left->is_thread = 1;
//    root->left->right->left->right = root->left->right->right;
//
//    root->left->right->right->is_thread = 1;
//    root->left->right->right->right = root->left->right;
//
//    root->left->right->is_thread = 1;
//    root->left->right->right = root->left;
//
//    root->left->is_thread = 1;
//    root->left->right = root->right->left->left;
//
//    root->right->left->left->is_thread = 1;
//    root->right->left->left->right = root->right->left->right;
//
//    root->right->left->right->is_thread = 1;
//    root->right->left->right->right = root->right->left;
//
//    root->right->left->is_thread = 1;
//    root->right->left->right = root->right->right->left;
//
//    root->right->right->left->is_thread = 1;
//    root->right->right->left->right = root->right->right->right;
//
//    root->right->right->right->is_thread = 1;
//    root->right->right->right->right = root->right->right;
//
//    root->right->right->is_thread = 1;
//    root->right->right->right = root->right;
//
//
//    root->right->is_thread = 1;
//    root->right->right = root;
//
//
//}
//
//
//TreeNode* Find_Post_SuccessorNode(TreeNode* node) {
//    
//    if (node->is_thread) {
//        return node->right;
//    }
//    return NULL;
//}
//
//
//
//
//
//
//// 후속자 노드를 찾는 함수
//TreeNode* Find_SuccessorNode(TreeNode* node) {
//    if (node->is_thread) {
//        return node->right; // 스레드가 설정되어 있으면 스레드 포인터로 이동
//    }
//
//    // 스레드가 아니므로 오른쪽 자식으로 이동한 후 가장 왼쪽 노드로 이동
//    node = node->right;
//    while (node && node->left != NULL)
//        node = node->left;
//
//    return node;
//}
//TreeNode* Find_preSuccessorNode(TreeNode* node) {
//
//
//    if (node->is_thread) {
//        return node->right; // 스레드가 설정되어 있으면 스레드 포인터로 이동
//    }
//
//    return NULL; // 더 이상 부모가 없으면 NULL 반환
//}
//
//
//void thread_inorder(TreeNode* root) {
//
//    setInorderThreads(root);
//    TreeNode* currentNode = root;
//
//    printf("In-order Traversal: ");
//
//    // 가장 왼쪽 노드(4)로 이동
//    while (currentNode->left != NULL) {
//        currentNode = currentNode->left;
//    }
//
//   
//    while (currentNode != NULL) {
//        printf("%d ", currentNode->data); // 현재 노드 데이터 출력
//        currentNode = Find_SuccessorNode(currentNode); // 후속자 노드 찾기 함수 호출
//        
//    }
//}
//
//void thread_preorder(TreeNode* root) {
//   
//    setPreorderThreads(root);
//    TreeNode* currentNode = root;
//
//    printf("\nPre-order Traversal: ");
//
//    while (currentNode != NULL) {
//        printf("%d ", currentNode->data); // 현재 노드 데이터 출력
//
//        // 왼쪽 자식으로 이동
//        if (currentNode->left != NULL) {
//            currentNode = currentNode->left;
//        }
//        else {
//            currentNode = Find_preSuccessorNode(currentNode); // 스레드 후속자 찾기
//        }
//    }
//
//}
//
//void thread_postorder(TreeNode* root) {
//
//    TreeNode* currentNode = root;
//
//    printf("\n Post-order Traversal: ");
//
//    while (currentNode != NULL) {
//        currentNode = currentNode->left;
//    }
//
//    while (currentNode != NULL) {
//        printf("%d ", currentNode->data); // 현재 노드 데이터 출력
//        currentNode = Find_Post_SuccessorNode(currentNode); // 후속자 노드 찾기 함수 호출
//    }
//
//
//
//}
//
//
//
//
//int main() {
//    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
//    root->data = 1;
//    root->left = NULL;
//    root->right = NULL;
//    root->is_thread = 0;
//
//    GenerateLinkTree(root);
//    thread_inorder(root);
//    
//    
//    thread_preorder(root);
//
//    setPostorderThreads(root);
//    thread_postorder(root);
//
//
//    return 0;
//}