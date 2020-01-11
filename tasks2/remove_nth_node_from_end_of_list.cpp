/*
https://leetcode.com/problems/remove-nth-node-from-end-of-list/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* mutable_head = head;
        ListNode* prev_from_removable = nullptr;
        ListNode* removable = nullptr;
        ListNode* next_from_removable = nullptr;
        int counter = 0;
        while (mutable_head) {
            ++counter;
            mutable_head = mutable_head->next;
            if (counter == n) {
                prev_from_removable = nullptr;
                removable = head;
                next_from_removable = head->next;
            } else if (counter > n) {
                prev_from_removable = removable;
                removable = next_from_removable;
                next_from_removable = next_from_removable->next;
            }
        }
        if (removable == head) {
            return next_from_removable;
        } else {
            prev_from_removable->next = next_from_removable;
        }
        return head;
    }
};
