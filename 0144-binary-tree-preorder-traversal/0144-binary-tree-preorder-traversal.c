/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(100 * sizeof(int));
    *returnSize = 0;

    if (root == NULL)
        return result;

    struct TreeNode* stack[100];
    int top = -1;

    stack[++top] = root;

    while (top != -1) {
        struct TreeNode* curr = stack[top--];

        result[(*returnSize)++] = curr->val;

        if (curr->right)
            stack[++top] = curr->right;

        if (curr->left)
            stack[++top] = curr->left;
    }

    return result;
}