/*
https://leetcode.com/problems/palindrome-number/

Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int64_t checker = 0;
        int x_mutable = x;
        while (x_mutable) {
            int digit = x_mutable % 10;
            checker = checker * 10 + digit;
            x_mutable = x_mutable / 10;
        }
        return checker == static_cast<int64_t>(x);
    }
};
