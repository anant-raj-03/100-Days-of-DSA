/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumOfLeftLeaves(struct TreeNode* root) {
    int helper(struct TreeNode* node, bool isLeft) {
        if (!node) return 0;
        if (!node->left && !node->right) { // leaf
            return isLeft ? node->val : 0;
        }
        return helper(node->left, true)  +
               helper(node->right, false);
    }

    return helper(root, false);    
}