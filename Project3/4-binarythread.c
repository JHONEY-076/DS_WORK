#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;



typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
	int is_thread; // ������ ���θ� ��Ÿ���� ����
} ThreadTree;

TreeNode* GenerateBinaryTree(int *inputData) {
	TreeNode*root
	

}


TreeNode*GenerateThreadTree(int* inputData) {



}

int main() {
	int inputData[] = { 4,1,9,13,15,3,6,14,7,10,12,2,5,8,7 };

	//Ʈ������, *root�� Ʈ���� ������ ��ȯ
	TreeNode*root = GenerateBinaryTree(inputData);
	BinaryTreeInOrder(root);
	ThreadTree* troot = GenerateThreadTree(inputData);
	ThreadTreeInOrder(troot);
	free(root);
	free(troot);
	return 0;
}



