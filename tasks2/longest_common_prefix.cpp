/*
https://leetcode.com/problems/longest-common-prefix/

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size()) {
            return "";
        }
        string ans = strs[0];
        for (size_t i = 1; i < strs.size(); ++i) {
            size_t length = min(strs[i].length(), ans.length());
            size_t j = 0;
            string tmp = "";
            while (j < length && strs[i][j] == ans[j]) {
                tmp += ans[j];
                ++j;
            }
            ans = tmp;
        }
        return ans;
    }
};
