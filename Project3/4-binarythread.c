#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;


typedef struct ThreadTree {
	int data;
	struct ThreadTree* left, * right;
	int is_thread; // 스레드 여부를 나타내는 변수
} ThreadTree;



TreeNode* new_node(int key) {
	TreeNode* temp = NULL;
	temp = malloc(sizeof(TreeNode));
	temp->data = key;
	temp->left = temp->right = NULL;
	
	return temp;
}

TreeNode* insert_node(TreeNode* root, int key) {
	if (root == NULL) {
		return new_node(key);
	}

	if (root->data == key) {
		return root;
	}
	else if (root->data > key) {
		root->left = insert_node(root->left, key);
	}
	else if (root->data < key) {
		root->right = insert_node(root->right, key);
	}
	return root;

}


TreeNode* GenerateBinaryTree(int inputData[]) {
	TreeNode* root = NULL;

	for (int i = 0; i < 15; i++) {
		root=insert_node(root, inputData[i]);
	}
	return root;

}


void BinaryTreeInOrder(TreeNode* root) {

	
	if (root != NULL) {

		BinaryTreeInOrder(root->left);
		printf("%d ", root->data);
		BinaryTreeInOrder(root->right);
	}


}





//TreeNode*GenerateThreadTree(int* inputData) {
//
//
//
//}

int main() {
	int inputData[] = { 4,1,9,13,15,3,6,14,7,10,12,2,5,8,7 };

	//트리생성, *root에 트리를 생성해 반환
	TreeNode*root = GenerateBinaryTree(inputData);
	BinaryTreeInOrder(root);
	/*ThreadTree* troot = GenerateThreadTree(inputData);
	ThreadTreeInOrder(troot);*/
	free(root);
	/*free(troot);*/
	return 0;
}



