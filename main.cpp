#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void printTreeTopToBottom(struct TreeNode* root) {
    if (root == NULL) return;


    struct TreeNode* queue[1000]; 
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        int levelSize = rear - front;
        for (int i = 0; i < levelSize; ++i) {
            struct TreeNode* node = queue[front++];
            printf("%d ", node->value);
            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }
        printf("\n");
    }
}

int main() {
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);

    printf("Árvore binária de cima para baixo:\n");
    printTreeTopToBottom(root);

    return 0;
}
