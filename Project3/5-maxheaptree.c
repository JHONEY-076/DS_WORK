#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct {
    int key;
} element;

typedef struct {
    element heap[MAX_SIZE];
    int heap_size;
} TreeNode;

// �� ���� �Լ�
TreeNode* create_heap() {
    return (TreeNode*)malloc(sizeof(TreeNode));
}

// �� �ʱ�ȭ �Լ�
void init_heap(TreeNode* h) {
    h->heap_size = 0;
}

// ���� �� ������ ��Ҹ� ������ִ� �Լ�
void display_heap(TreeNode* h) {
    for (int i = 1; i <= h->heap_size; i++) {
        printf("%02d ", h->heap[i].key); // �� �������� ��Ҹ� �� �ڸ��� ���
    }
    printf("\n");
}


// �ʱ�ȭ�� �迭�� �ִ� ���� ��带 �߰��Ͽ� Heapfiy�Ǵ� �Լ�(������ ���������� �ʴ´�)
void InsertMaxHeapTree1(TreeNode* h, element data) {

    //���� ��������쿡 ���
    if (h->heap_size >= MAX_SIZE - 1) {
        printf("���� ���� á���ϴ�!\n");
        return;
    }

    int i = h->heap_size + 1; // �� �迭�� �ε��� 1 ���� ����
    int count = 0;  // ��尡 �̵��� Ƚ���� ī��Ʈ ���ش�.



    // 1. ���� ������� ��带 �����ϴ� ��
    h->heap[i] = data;
    (h->heap_size)++;
   



    // 2. �θ�� ���ϸ� Upheap�� ������� ���� ����Ʈ���� ������ ����(heapfiy)�����ִ� ��

    while ((i != 1) && (h->heap[i / 2].key < data.key)) { // i�� 1�� �ƴϰ� �ش� �ε����� �����Ͱ� �θ��� ������ Ŭ������ �ݺ����ش�!!

        int parentIndex = i / 2; // �θ��ε���

        // �θ� �ڽ� ��ġ�� �̵�(SWAP)
        element temp = h->heap[i];
        h->heap[i] = h->heap[parentIndex];
        h->heap[parentIndex] = temp;


       
        count++;// ��尡 �̵��� Ƚ���� ī��Ʈ ���ش�.


        i = parentIndex; // i�� �θ� ��ġ�� �ε����� �̵���Ų��.
    }

   
}


// �ִ� ���� ��带 �߰��ϰ� heapfiy �Ǵ� ������ �����ִ� �Լ�
void InsertMaxHeapTree(TreeNode* h, element data) {
    
    //���� ��������쿡 ���
    if (h->heap_size >= MAX_SIZE - 1) {
        printf("���� ���� á���ϴ�!\n");
        return; 
    }

    int i = h->heap_size + 1; // �� �迭�� �ε��� 1 ���� ����
    int count = 0;  // ��尡 �̵��� Ƚ���� ī��Ʈ ���ش�.



    // 1. ���� ������� ��带 �����ϴ� ��
    h->heap[i] = data;
    (h->heap_size)++;
    display_heap(h); // ���迭�� �߰��� ���� ���� ���



    // 2. �θ�� ���ϸ� Upheap�� ������� ���� ����Ʈ���� ������ ����(heapfiy)�����ִ� ��

    while ((i != 1) && (h->heap[i / 2].key < data.key)) { // i�� 1�� �ƴϰ� �ش� �ε����� �����Ͱ� �θ��� ������ Ŭ������ �ݺ����ش�!!
        
        int parentIndex = i / 2; // �θ��ε���

        // �θ� �ڽ� ��ġ�� �̵�(SWAP)
        element temp = h->heap[i];
        h->heap[i]= h->heap[parentIndex];
        h->heap[parentIndex]=temp;

        
        display_heap(h);// ���� �� ���� ��� 
        count++;// ��尡 �̵��� Ƚ���� ī��Ʈ ���ش�.

       
        i = parentIndex; // i�� �θ� ��ġ�� �ε����� �̵���Ų��.
    }
   
    printf("��尡 �̵��� Ƚ��: %d\n", count);
}
 

// �����Լ��� �迭�� ������ �ִ����� �����ϴ� �Լ�
TreeNode* generateMaxHeapTree(int inputData[], int size) {
    TreeNode* heap = create_heap();
    if (heap == NULL) {
        printf("�Ҵ�� �޸𸮰� �����ϴ�.\n");
        exit(1); 
    }
    init_heap(heap); // �� �ʱ�ȭ 

    for (int i = 0; i < size; i++) { // �迭�� ����ִ� ��Ҹ� size��ŭ insert���ִ°�
        InsertMaxHeapTree1(heap, (element) { inputData[i] });
    }

    return heap; // ������ �� ����
}

// �ִ����� �����ϴ� �Լ�
void delete_heap(TreeNode* h) {
    int parent, child;
    element item, temp;
    int count = 0; // �̵� Ƚ�� ī��Ʈ

    if (h->heap_size == 0) { // ���� ������� ��� 
        printf("���� ��� �ֽ��ϴ�!\n");
        return; 
    }

    item = h->heap[1]; // ��Ʈ ��� ����
    temp = h->heap[h->heap_size]; // ������ ��� ����

    (h->heap_size)--; // �� ũ�� ����



    // ��Ʈ ��忡 ������ ��带 ������ �� �� ���� ���
    h->heap[1] = temp;
    count++;
    display_heap(h); // ������ ��带 ��Ʈ�� ������ ������ ���

    
    
    // Heapify , ��Ʈ���� �����Ͽ� �ڽ� ���� ��������(��������ش�)
    for (parent = 1, child = 2;
        child <= h->heap_size;
        parent = child, child = child * 2) { // child�� ���� �ڽ� ����� �ε���

        // ���� ����� �� �ڽ� �� �� ū �ڽ����� child�� ������Ʈ ���ִ� ��!!!! 
        if ((child < h->heap_size) && (h->heap[child].key < h->heap[child + 1].key)) // ���� ���� �ڽ��� heap_size���� �۰� ���� �ڽ��� ������ �ڽ��� ������ ������  
            child++;                                                                 // child�� ������ �ڽ����� ������Ʈ ���ش�.

        // temp�� �ڽ� ��庸�� ũ�� ���� ����
        if (temp.key >= h->heap[child].key)
            break;

        // ���� �� �ڽ� ��� �� ū ��带 �θ� ���� �̵�Ű�� ��!!! (SWAP)
        element temp = h->heap[parent];
        h->heap[parent] = h->heap[child];
        h->heap[child] = temp;

        count++;

       
        display_heap(h); // �̵��� ���� ������ ���
    }

  
    printf("��尡 �̵��� Ƚ��: %d\n", count);
}



// ���� �������� ����ϴ� �Լ�
void level_display(TreeNode* h) {
    if (h->heap_size == 0) {
        printf("���� ��� �ֽ��ϴ�.\n");
        return;
    }

    int level = 1;
    int level_node_size = 1; // ���� ������ ��� ��
    int index = 1;      // ������ ����� ����� �ε���

    while (index <= h->heap_size) {  
        printf("[%d] ", level);
        for (int j = 0; j < level_node_size && index <= h->heap_size; j++) { //���� ������ ����� ���� �������� ��ŭ 
                                                                             //����� ���� �ε����� ��� ���ִ� ��!!
            printf("%02d ", h->heap[index].key);
            index++;
        }
        printf("\n");
        level++;
        level_node_size *= 2; // ���� ������ ��� ���� �� ��� ���� => ���� ����Ʈ���̱� ������ �ܸ���带 ������ ������ ������ 2�辿 �����Ѵ�.
    }
}


// ����� �������̽� �Լ�
void runUserInterface(TreeNode* root) {
    char c = 0;
    int a = 0;

    for (;;) {
        printf("----------------------\n");
        printf("| i  : ��� �߰�    |\n");
        printf("| d  : ��� ����    |\n");
        printf("| p  : ������ ���  |\n");
        printf("| c  : ����         |\n");
        printf("----------------------\n");

        printf("�޴� �Է�: ");
        scanf_s(" %c", &c, 1); 

        switch (c) {
        case 'i':
            printf("�߰��� �� �Է�: ");
            scanf_s("%d", &a); 
            InsertMaxHeapTree(root, (element) { a }); // ����ڰ� �Է��� ���� ���� �߰�
            break;
        case 'd':
            delete_heap(root);

            break;

        case 'p':
            level_display(root);
            break;

        case 'c':
            free(root); // ���� �Ҵ�� �޸� ����
            exit(0);
            break;
        default:
            printf("�ٽ��Է����ּ���.\n");
        }
    }
}

int main() {
    int inputData[] = { 90, 89, 70, 36, 75, 63, 65, 21, 18, 15 };
    int size = sizeof(inputData) / sizeof(inputData[0]); // �迭 ũ�� ���

    TreeNode* root = generateMaxHeapTree(inputData, size);
    runUserInterface(root); 

    free(root); 

    return 0;
}
