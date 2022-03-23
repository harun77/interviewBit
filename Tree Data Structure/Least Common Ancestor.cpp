https://www.interviewbit.com/problems/least-common-ancestor/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int a, b; 
bool foundA, foundB;

TreeNode* solve(TreeNode* node) {
    if(!node) return NULL;

    if(node->val == a) foundA = 1;
    if(node->val == b) foundB = 1;

    TreeNode* L = solve(node->left);
    TreeNode* R = solve(node->right);

    if(node->val == a || node->val == b) return node;

    if(L && R) return node;
    if(L) return L;
    return R;
}

int Solution::lca(TreeNode* A, int B, int C) {
    a = B; b = C;
    foundA = foundB = 0;
    TreeNode* ans = solve(A);
    if(!foundA || !foundB) return -1;
    return ans->val;
}
