https://www.interviewbit.com/problems/insertion-sort-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* A) {
    ListNode* sorted = NULL;

    while(A) {
        auto curr = A;
        A = A->next;
        if(!sorted || curr->val <= sorted->val) {
            curr->next = sorted;
            sorted = curr;
        } else {
            auto left = sorted;
            auto right = sorted->next;

            while(right && right->val < curr->val) {
                left = left->next;
                right = right->next;
            }
            left->next = curr;
            curr->next = right;
        }
    }
    return sorted;
}
