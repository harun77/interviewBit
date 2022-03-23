https://www.interviewbit.com/problems/sort-list/

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

ListNode* Solution::sortList(ListNode* A) {
    vector<ListNode*>ara;
    while(A) {
        ara.push_back(A);
        A=A->next;
    }
    sort(ara.begin(), ara.end(), comp);
    ListNode* ret = new ListNode(0);
    ListNode* ans = ret;
    for(int i=0;i<ara.size();i++) {
        ret->next=ara[i];
        ret=ret->next;
    }
    ret->next=NULL;
    return ans->next;
}
