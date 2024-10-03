//#include <stdio.h>
//
//typedef enum { FALSE, TRUE } bool;
//typedef struct TreeNode {
//    int data;
//    struct TreeNode* left, * right;
//    int is_thread; // ���� ������ ��ũ�� �������̸� True
//} TreeNode;
//
//TreeNode* find_successor(TreeNode* t) {
//    
//    // ������ �ּ� ������ �߱⶧���� 
//    /*n1.right = &n3; =>A�� C�� ����Ű�� 
//    n2.right = &n7; => B�� G�� ����Ű�� 
//    n4.right = &n6; => D�� F�� ����ų �� �ִ�.!!     */ 
//
//    TreeNode* pright = t->right;
//
//    //���� ������ �����Ͱ� NULL�̰ų� �����尡 �����Ǿ� ������ ������ �����ͷ� �̵�
//    if (pright == NULL || t->is_thread == TRUE)
//        return pright;
//    
//
//    // ���� IF������ �����尡 �ƴѰ��� Ȯ�������Ƿ�,
//    // ������ �ڽ����� �̵��� �� ���� ���� ���� �̵�
// 
//    while (pright->left != NULL)
//        pright = pright->left;
//
//    return pright;
//}
//
////������ ���� ������ȸ �Լ� �ۼ�
//void thread_inorder(TreeNode* t) {
//    TreeNode* r = t;
//    while (r->left != NULL)
//        r = r->left;
//
//    do {
//        printf("%c ", r->data); 
//        r = find_successor(r); //�ļ��� �Լ� ȣ��
//    } while (r != NULL);
//}
//
//int main() {
//    TreeNode n1 = { 'A', NULL, NULL, 1 };
//    TreeNode n2 = { 'B', NULL, NULL, 1 };
//    TreeNode n3 = { 'C', &n1, &n2, 0 };
//    TreeNode n4 = { 'D', NULL, NULL, 1 };
//    TreeNode n5 = { 'E', NULL, NULL, 0 };
//    TreeNode n6 = { 'F', &n4, &n5, 0 };
//    TreeNode n7 = { 'G', &n3, &n6, 0 };
//    TreeNode* exp = &n7;
//
//    // ������ �����ϴ� ��!!!!!!!!!
//    n1.right = &n3;
//    n2.right = &n7;
//    n4.right = &n6;
//
//    thread_inorder(exp);
//
//    return 0;
//}
//
//
//    //G
//   /// \
//  //C   F
// /// \ / \
////A   B D E
