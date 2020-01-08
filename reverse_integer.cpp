/*
https://leetcode.com/problems/reverse-integer/

Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

class Solution {
public:
    int reverse(int x) {
        int multiplier = 1;
        if (x < 0) {
            multiplier = -1;
        }
        int result = 0;
        while (x) {
            if (multiplier == 1 && ((INT_MAX - x % 10) / 10 < result) ||
                multiplier == -1 && ((INT_MIN - x % 10) / 10 > result)) {
                return 0;
            }
            result = result * 10 + x % 10;
            x = x / 10;
        }
        return result;
    }
};
