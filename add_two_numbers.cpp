/*
https://leetcode.com/problems/add-two-numbers/

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
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
    ListNode* ChangeCurNode(ListNode* cur_node, int value) {
        cur_node->next = new ListNode(value);
        cur_node = cur_node->next;
        return cur_node;
    }
    
    int TryGetValue(ListNode* node) {
        return node ? node->val : 0;
    }
    
    ListNode* TryGetNext(ListNode* node) {
        return node ? node->next : NULL;
    }

public:
    ListNode* addTwoNumbers(ListNode* from1, ListNode* from2) {
        ListNode* start = new ListNode(0);
        ListNode* to = start;
        while (true) {
            int value = to->val + TryGetValue(from2) +
                TryGetValue(from1);
            to->val = value % 10;
            int prev_rest = value / 10;
            from1 = TryGetNext(from1);
            from2 = TryGetNext(from2);
            if (from1 || from2 || prev_rest) {
                to = ChangeCurNode(to, prev_rest);
            } else {
                break;
            }
        }
        return start;
    }
};
