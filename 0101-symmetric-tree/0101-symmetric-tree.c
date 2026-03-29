bool isMirror(struct TreeNode* left, struct TreeNode* right) {
    // Case 1: both NULL → symmetric
    if (left == NULL && right == NULL)
        return true;

    // Case 2: one NULL → not symmetric
    if (left == NULL || right == NULL)
        return false;

    // Case 3: values must match + recursive mirror check
    return (left->val == right->val) &&
           isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root) {
    // Empty tree is symmetric
    if (root == NULL)
        return true;

    // Check left and right subtree
    return isMirror(root->left, root->right);
}