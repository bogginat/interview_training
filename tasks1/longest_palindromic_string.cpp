/*
https://leetcode.com/problems/longest-palindromic-substring/


Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
*/

class Solution {
    void CheckPalindrome(string& s, int start, int end,
                         int& result_start, int& result_end) {
        while (start >= 0 && end < s.size() && s[start] == s[end]) {
            --start;
            ++end;
        }
        ++start;
        --end;
        if (result_end - result_start < end - start) {
            result_end = end;
            result_start = start;
        }
    }
public:
    string longestPalindrome(string s) {
        int result_start = 0, result_end = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            if (i + 1 < s.size() && s[i] == s[i + 1]) {
                CheckPalindrome(s, i, i + 1, result_start, result_end);
            }
            CheckPalindrome(s, i, i, result_start, result_end);
        }
        return {s.begin() + result_start, s.begin() + result_end + 1};
    }
};
