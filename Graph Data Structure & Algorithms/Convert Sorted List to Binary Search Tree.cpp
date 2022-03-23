https://www.interviewbit.com/problems/convert-sorted-list-to-binary-search-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* root;

TreeNode* solve(int s, int e) {
    if(s>e) return NULL;
    int mid = s+(e-s)/2;
    TreeNode* left = solve(s, mid-1);
    TreeNode* node = new TreeNode(root->val);
    root=root->next; 
    TreeNode* right = solve(mid+1, e);
    node->left = left;
    node->right = right;
    return node;
}

TreeNode* Solution::sortedListToBST(ListNode* A) {
    ListNode* head = A;
    int L = 0;
    while(head) {
        ++L;
        head = head->next;
    }
    root = A;
    return solve(0, L-1);
}
