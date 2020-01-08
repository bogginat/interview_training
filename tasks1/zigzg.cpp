/*
https://leetcode.com/problems/zigzag-conversion/

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
*/
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == s.length() || numRows == 1) {
            return s;
        }
        string ans = "";
        for (size_t i = 0; i < numRows; ++i) {
            size_t tmp = i;
            while (tmp < s.length()) {
                if (i != numRows - 1) {
                  ans += s[tmp];
                  tmp = tmp + (2 * numRows - 2 * (i + 1));
                }
                if (tmp < s.length() && i) {
                    ans += s[tmp];
                    tmp = tmp + 2 * i;                    
                }
            }
        }
        return ans;
    }
};
