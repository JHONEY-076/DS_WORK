#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;



typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
	int is_thread; // 스레드 여부를 나타내는 변수
} ThreadTree;

TreeNode* GenerateBinaryTree(int *inputData) {
	TreeNode*root
	

}


TreeNode*GenerateThreadTree(int* inputData) {



}

int main() {
	int inputData[] = { 4,1,9,13,15,3,6,14,7,10,12,2,5,8,7 };

	//트리생성, *root에 트리를 생성해 반환
	TreeNode*root = GenerateBinaryTree(inputData);
	BinaryTreeInOrder(root);
	ThreadTree* troot = GenerateThreadTree(inputData);
	ThreadTreeInOrder(troot);
	free(root);
	free(troot);
	return 0;
}



