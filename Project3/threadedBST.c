//#include <stdio.h>
//
//typedef enum { FALSE, TRUE } bool;
//typedef struct TreeNode {
//    int data;
//    struct TreeNode* left, * right;
//    int is_thread; // 만약 오른쪽 링크가 스레드이면 True
//} TreeNode;
//
//TreeNode* find_successor(TreeNode* t) {
//    
//    // 쓰레드 주소 설정을 했기때문에 
//    /*n1.right = &n3; =>A는 C를 가리키고 
//    n2.right = &n7; => B는 G를 가리키고 
//    n4.right = &n6; => D는 F를 가리킬 수 있다.!!     */ 
//
//    TreeNode* pright = t->right;
//
//    //만약 오른쪽 포인터가 NULL이거나 스레드가 설정되어 있으면 스레드 포인터로 이동
//    if (pright == NULL || t->is_thread == TRUE)
//        return pright;
//    
//
//    // 위의 IF문에서 스레드가 아닌것을 확인했으므로,
//    // 오른쪽 자식으로 이동한 후 가장 왼쪽 노드로 이동
// 
//    while (pright->left != NULL)
//        pright = pright->left;
//
//    return pright;
//}
//
////쓰레드 버전 중위순회 함수 작성
//void thread_inorder(TreeNode* t) {
//    TreeNode* r = t;
//    while (r->left != NULL)
//        r = r->left;
//
//    do {
//        printf("%c ", r->data); 
//        r = find_successor(r); //후속자 함수 호출
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
//    // 스레드 설정하는 곳!!!!!!!!!
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
