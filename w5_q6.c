#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* sortedArrayToBST(int* nums, int left, int right) {
    if (left > right) {
        return NULL;
    }
    int mid = left + (right - left) / 2;

    struct TreeNode* root = createNode(nums[mid]);

    root->left = sortedArrayToBST(nums, left, mid - 1);
    root->right = sortedArrayToBST(nums, mid + 1, right);

    return root;
}
struct TreeNode* convertSortedArrayToBST(int* nums, int size) {
    return sortedArrayToBST(nums, 0, size - 1);
}

void printInOrder(struct TreeNode* root) {
    if (root != NULL) {
        printInOrder(root->left);
        printf("%d ", root->val);
        printInOrder(root->right);
    }
}

int main() {
    int nums[] = {-10, -3, 0, 5, 9};
    int size = sizeof(nums) / sizeof(nums[0]);

    struct TreeNode* root = convertSortedArrayToBST(nums, size);

    printf("In-order traversal of the BST: ");
    printInOrder(root);
    printf("\n");

    return 0;
}
