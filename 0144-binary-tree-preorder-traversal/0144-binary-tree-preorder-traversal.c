/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void preorder(struct TreeNode* root, int* arr, int* index){
    if(root == NULL)
        return;

    arr[(*index)++] = root->val;   // Root
    preorder(root->left, arr, index);   // Left
    preorder(root->right, arr, index);  // Right
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    
    int* result = (int*)malloc(100 * sizeof(int)); 
    int index = 0;

    preorder(root, result, &index);

    *returnSize = index;
    return result;
}