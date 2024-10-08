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



//TreeNode* new_node(int key) {
//	TreeNode* temp = NULL;
//	temp = malloc(sizeof(TreeNode));
//	temp->data = key;
//	temp->left = temp->right = NULL;
//	
//	return temp;
//}
//
//TreeNode* insert_node(TreeNode* root, int key) {
//	if (root == NULL) {
//		return new_node(key);
//	}
//
//	if (root->data == key) {
//		return root;
//	}
//	else if (root->data > key) {
//		root->left = insert_node(root->left, key);
//	}
//	else if (root->data < key) {
//		root->right = insert_node(root->right, key);
//	}
//	return root;
//
//}
//
//
//TreeNode* GenerateBinaryTree(int inputData[]) {
//	TreeNode* root = NULL;
//
//	for (int i = 0; i < 15; i++) {
//		root=insert_node(root, inputData[i]);
//	}
//	return root;
//
//}
//
//
//void BinaryTreeInOrder(TreeNode* root) {
//
//	
//	if (root != NULL) {
//
//		BinaryTreeInOrder(root->left);
//		printf("%d ", root->data);
//		BinaryTreeInOrder(root->right);
//	}
//
//
//}









ThreadTree* new_thread_node(int key) {
	ThreadTree* temp = NULL;
	temp = malloc(sizeof(ThreadTree));
	temp->data = key;
	temp->left = temp->right = NULL;
	temp->is_thread = 0;

	return temp;
}

ThreadTree* insert_Thread_node(ThreadTree* root, int key) {
	if (root == NULL) {
		return new_thread_node(key);
	}

	if (root->data == key) {
		return root;
	}
	else if (root->data > key) {
		root->left = insert_Thread_node(root->left, key);
	}
	else if (root->data < key) {
		root->right = insert_Thread_node(root->right, key);
	}
	return root;

}


ThreadTree*GenerateThreadTree(int inputData[]) {
	ThreadTree* root = NULL;

	for (int i = 0; i < 15; i++) {
		root = insert_Thread_node(root, inputData[i]);
	}
	return root;

}


void setInorderThreads(ThreadTree* root) {
	if (root == NULL) return;

	root->left->right->left->is_thread = 1;
	root->left->right->left->right = root->left->right;


	root->left->right->is_thread = 1;
	root->left->right->right = root;

	root->right->left->left->is_thread = 1;
	root->right->left->left->right = root->right->left;

	root->right->left->right->right->is_thread = 1;
	root->right->left->right->right->right = root->right;

	root->right->right->left->right->left->is_thread = 1;
	root->right->right->left->right->left->right = root->right->right->left->right;

	root->right->right->left->right->is_thread = 1;
	root->right->right->left->right->right = root->right->right;

	root->right->right->right->left->is_thread = 1;
	root->right->right->right->left->right = root->right->right->right;
}





ThreadTree*Find_Successor_inorder_Node(ThreadTree* node) {

	if (node->is_thread) {
		return node->right;
	}

	return NULL;

}





void ThreadTreeInOrder(ThreadTree* root) {

	setInorderThreads(root);
	ThreadTree* currentNode = root;

	printf("\nThread tree inorder: ");
	

	while (currentNode->left != NULL) {
		currentNode = currentNode->left;
	}

	while (currentNode != NULL) {
		printf("%d", currentNode->data);
		currentNode = Find_Successor_inorder_Node(currentNode);

	}


}




int main() {
	int inputData[] = { 4,1,9,13,15,3,6,14,7,10,12,2,5,8,7 };

	//트리생성, *root에 트리를 생성해 반환
	/*TreeNode*root = GenerateBinaryTree(inputData);
	printf("Binary tree inorder: ");
	BinaryTreeInOrder(root);*/
	ThreadTree* troot = GenerateThreadTree(inputData);
	ThreadTreeInOrder(troot);
	/*free(root);*/
	free(troot);
	return 0;
}



