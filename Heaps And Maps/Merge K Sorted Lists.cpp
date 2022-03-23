https://www.interviewbit.com/problems/merge-k-sorted-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
bool comp(ListNode* a, ListNode* b) {
    return a->val <= b->val;
} 

ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    vector<ListNode*>list;
    int n = A.size();
    for(int i=0;i<n;i++) {
        auto curr = A[i];
        while(curr) {
            list.push_back(curr);
            curr = curr->next;
        }
    }
    sort(list.begin(), list.end(), comp);
    ListNode* res = NULL;
    for(int i=list.size()-1; i>=0; i--) { 
        list[i]->next = res;
        res = list[i];
    }
    return res;
}

// 3
// 3 1  10  20
// 3 4  11 13
// 3 3  8  9