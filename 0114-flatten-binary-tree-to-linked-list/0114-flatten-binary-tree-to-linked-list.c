void helper(struct TreeNode* root, struct TreeNode** prev) {
    if (root == NULL) return;

    helper(root->right, prev);
    helper(root->left, prev);

    root->right = *prev;
    root->left = NULL;

    *prev = root;
}

void flatten(struct TreeNode* root) {
    struct TreeNode* prev = NULL;
    helper(root, &prev);
}