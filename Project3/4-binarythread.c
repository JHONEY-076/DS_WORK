#include <stdio.h>
#include <stdlib.h>

// ����Ʈ������ü
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

// ������ ����Ʈ�� ����ü
typedef struct ThreadTree {
	int data;
	struct ThreadTree* left, * right;
	int is_thread; // ������ ���θ� ��Ÿ���� ����
} ThreadTree;


// ���ο� ��� ����
TreeNode* new_node(int key) {
	TreeNode* temp = NULL;
	temp = malloc(sizeof(TreeNode));
	temp->data = key;
	temp->left = temp->right = NULL;

	return temp;
}

TreeNode* insert_node(TreeNode* root, int key) {

	//��尡 ������ ���ο� ��� ����
	if (root == NULL) {
		return new_node(key);
	}
	// ����� �����Ͱ� �����Ϸ��� ����� �����Ϳ� ������ ����
	if (root->data == key) {
		return root;
	}
	// ����� �����Ͱ� �����Ϸ��� ����� �����ͺ��� �۴ٸ� ����� ���ʿ� ���ο� ��带 �����Ѵ�.
	else if (root->data > key) {
		root->left = insert_node(root->left, key);
	}
	//����� �����Ͱ� �����Ϸ��� ����� �����ͺ��� ũ�ٸ� ����� �������� ���ο� ��带 �����Ѵ�.
	else if (root->data < key) {
		root->right = insert_node(root->right, key);
	}
	return root;

}


TreeNode* GenerateBinaryTree(int inputData[]) {
	TreeNode* root = NULL;

	for (int i = 0; i < 15; i++) {
		root = insert_node(root, inputData[i]);
	}
	return root;

}

// ����Ʈ�� ������ȸ 
void BinaryTreeInOrder(TreeNode* root) {


	if (root != NULL) {

		BinaryTreeInOrder(root->left);
		printf("%d ", root->data);
		BinaryTreeInOrder(root->right);
	}
}


//���ο� ��� ����
ThreadTree* new_thread_node(int key) {
	ThreadTree* temp = malloc(sizeof(ThreadTree));
	if (!temp) {
		fprintf(stderr, "�޸� �Ҵ� ����\n");
		exit(EXIT_FAILURE);
	}
	temp->data = key;
	temp->left = temp->right = NULL;
	temp->is_thread = 0; // �������� �ʱⰪ�� ��� 0���� �ʱ�ȭ ���ش�.
	return temp;
}





ThreadTree* insert_Thread_node(ThreadTree* root, int key) {

	//��尡 ������ �� ��� ����
	if (root == NULL) {
		return new_thread_node(key);
	}

	//�ش� ����� �����Ϳ� ������ ����� �����Ͱ� ���ٸ� ����
	if (root->data == key) {
		return root;
	}
	//�ش� ����� �����ͺ��� ������ ����� �����Ͱ� �۴ٸ� �ش� ����� �������� ����
	else if (root->data > key) {
		root->left = insert_Thread_node(root->left, key);
	}
	//�ش� ����� �����ͺ��� ������ ����� �����Ͱ� ũ�ٸ� �ش� ����� ���������� ����
	else {
		root->right = insert_Thread_node(root->right, key);
	}

	return root;
}


ThreadTree* GenerateThreadTree(int inputData[]) {
	ThreadTree* root = NULL;

	for (int i = 0; i < 15; i++) {
		root = insert_Thread_node(root, inputData[i]); // �Ҵ�� �迭�� ���Ҹ� Ʈ���� �������ش�.
	}
	return root;

}

// ������ ������ȸ ����
void setInorderThreads(ThreadTree* root) {
	if (root == NULL) return;

	root->left->right->left->is_thread = 1;	//2�� ������� ǥ�� 
	root->left->right->left->right = root->left->right; //2�� �������� 3�� ����Ŵ 


	root->left->right->is_thread = 1;	//3�� ������� ǥ��
	root->left->right->right = root;	//3�� �������� 4�� ����Ŵ 

	root->right->left->left->is_thread = 1;		// 5�� ������� ǥ��
	root->right->left->left->right = root->right->left;	// 5�� �����ʿ� 6�� ����Ŵ 

	root->right->left->right->right->is_thread = 1; //8�� ������� ǥ��
	root->right->left->right->right->right = root->right;	// 8�� �������� 9�� ����Ŵ

	root->right->right->left->right->left->is_thread = 1; // 11�� ������� ǥ��
	root->right->right->left->right->left->right = root->right->right->left->right;	 // 11�� �������� 12�� ����Ŵ

	root->right->right->left->right->is_thread = 1; // 12�� ������� ǥ�� 
	root->right->right->left->right->right = root->right->right; // 12�� �������� 13�� ����Ŵ

	root->right->right->right->left->is_thread = 1; // 14�� ������� ǥ�� 
	root->right->right->right->left->right = root->right->right->right;	// 14�� �������� 15�� ����Ŵ
}




//������ ������ȸ
void ThreadTreeInOrder(ThreadTree* root) {
	setInorderThreads(root);
	ThreadTree* currentNode = root;

	//cuurentNode�� NULL�϶����� ���� �ڽ����� �̵�
	while (currentNode && currentNode->left) {
		currentNode = currentNode->left;
	}

	printf("\nThread tree inorder:  ");
	while (currentNode != NULL) {
		printf("%d ", currentNode->data);
		if (currentNode->is_thread) {
			currentNode = currentNode->right; // �����带 ���� �̵�
		}
		else {
			currentNode = currentNode->right; // �Ϲ� ��ũ�� ���� �̵�
			while (currentNode && currentNode->left) {
				currentNode = currentNode->left; // �����ڽ��� ������ �̵�
			}
		}
	}
}



int main() {
	int inputData[] = { 4,1,9,13,15,3,6,14,7,10,12,2,5,8,11 };

	//Ʈ������, *root�� Ʈ���� ������ ��ȯ
	TreeNode* root = GenerateBinaryTree(inputData);
	printf("Binary tree inorder: ");
	BinaryTreeInOrder(root);

	ThreadTree* troot = GenerateThreadTree(inputData);
	ThreadTreeInOrder(troot);

	free(root);
	free(troot);

	return 0;
}