https://www.interviewbit.com/problems/sum-root-to-leaf-numbers/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define mod 1003
int ans;

void solve(TreeNode* node, int n) {
    n = (n*10+node->val)%mod;
    if(!node->left && !node->right) { 
        ans = (ans+n)%mod;
        return;
    }    
    if(node->left) solve(node->left, n);
    if(node->right) solve(node->right, n);
}

int Solution::sumNumbers(TreeNode* A) {
    ans=0;
    solve(A, 0);
    return ans;
}
