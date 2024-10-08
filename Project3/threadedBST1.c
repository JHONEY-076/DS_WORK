//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct TreeNode {
//    int data;
//    struct TreeNode* left, * right;
//    int is_thread; // ������ ���θ� ��Ÿ���� ����
//} TreeNode;
//
//// �Լ� ������Ÿ�� ����
//void setInorderThreads(TreeNode* root);
//
//void PlaceNode(TreeNode* root, int direction, int data) {
//    TreeNode* newNode = malloc(sizeof(TreeNode));
//    newNode->data = data;
//    newNode->left = NULL;
//    newNode->right = NULL;
//    newNode->is_thread = 0; // ������ �ƴ��� ǥ��
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
//    // ������ ����
//    root->left->left->left->is_thread = 1; // 4�� ���������� ǥ��
//    root->left->left->left->right = root->left->left; // 4�� ������ �����Ͱ� 3�� ����Ŵ
//
//    root->left->left->right->is_thread = 1; // 6�� ���������� ǥ��
//    root->left->left->right->right = root->left; // 6�� ������ �����Ͱ� 2�� ����Ŵ
//
//    root->left->right->left->is_thread = 1; // 5�� ������ ����
//    root->left->right->left->right = root->left->right; // 7�� ������ �����Ͱ� 5�� ����Ŵ
//
//    root->left->right->right->is_thread = 1; // 8�� ���������� ǥ��
//    root->left->right->right->right = root; // 8�� ������ �����Ͱ� 1�� ����Ŵ
//
//    root->right->left->left->is_thread = 1; // 11�� ������ �����带 10���� ����
//    root->right->left->left->right = root->right->left; // 11�� ������ �����Ͱ� 10�� ����Ŵ
//
//    root->right->left->right->is_thread = 1; // 12�� ���������� ǥ��
//    root->right->left->right->right = root->right; // 12�� ������ �����Ͱ� 9�� ����Ŵ
//
//    root->right->right->left->is_thread = 1; // 14�� ���������� ǥ��
//    root->right->right->left->right = root->right->right; // 14�� ������ �����Ͱ� 13�� ����Ŵ
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
//// �ļ��� ��带 ã�� �Լ�
//TreeNode* Find_SuccessorNode(TreeNode* node) {
//    if (node->is_thread) {
//        return node->right; // �����尡 �����Ǿ� ������ ������ �����ͷ� �̵�
//    }
//
//    // �����尡 �ƴϹǷ� ������ �ڽ����� �̵��� �� ���� ���� ���� �̵�
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
//        return node->right; // �����尡 �����Ǿ� ������ ������ �����ͷ� �̵�
//    }
//
//    return NULL; // �� �̻� �θ� ������ NULL ��ȯ
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
//    // ���� ���� ���(4)�� �̵�
//    while (currentNode->left != NULL) {
//        currentNode = currentNode->left;
//    }
//
//   
//    while (currentNode != NULL) {
//        printf("%d ", currentNode->data); // ���� ��� ������ ���
//        currentNode = Find_SuccessorNode(currentNode); // �ļ��� ��� ã�� �Լ� ȣ��
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
//        printf("%d ", currentNode->data); // ���� ��� ������ ���
//
//        // ���� �ڽ����� �̵�
//        if (currentNode->left != NULL) {
//            currentNode = currentNode->left;
//        }
//        else {
//            currentNode = Find_preSuccessorNode(currentNode); // ������ �ļ��� ã��
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
//        printf("%d ", currentNode->data); // ���� ��� ������ ���
//        currentNode = Find_Post_SuccessorNode(currentNode); // �ļ��� ��� ã�� �Լ� ȣ��
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