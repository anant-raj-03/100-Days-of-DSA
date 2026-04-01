#include <stdlib.h>

// Helper function to create a new node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Function to find index of value in inorder array
int findIndex(int* inorder, int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

// Recursive function
struct TreeNode* build(int* inorder, int inStart, int inEnd,
                       int* postorder, int* postIndex) {
    
    if (inStart > inEnd)
        return NULL;

    // Get current root from postorder
    int rootVal = postorder[*postIndex];
    (*postIndex)--;

    struct TreeNode* root = createNode(rootVal);

    // If only one node
    if (inStart == inEnd)
        return root;

    // Find root in inorder
    int inIndex = findIndex(inorder, inStart, inEnd, rootVal);

    // IMPORTANT: build right subtree first
    root->right = build(inorder, inIndex + 1, inEnd, postorder, postIndex);
    root->left  = build(inorder, inStart, inIndex - 1, postorder, postIndex);

    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    int postIndex = postorderSize - 1;
    return build(inorder, 0, inorderSize - 1, postorder, &postIndex);
}