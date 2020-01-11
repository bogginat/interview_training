/*
https://leetcode.com/problems/integer-to-roman/

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: 3
Output: "III"
Example 2:

Input: 4
Output: "IV"
Example 3:

Input: 9
Output: "IX"
Example 4:

Input: 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 5:

Input: 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/

class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        unordered_map<int, string> romans =
        {{1, "I"}, {5, "V"}, {10, "X"}, {50, "L"},
         {100, "C"}, {500, "D"}, {1000, "M"}, {4, "IV"},
         {9, "IX"}, {90, "XC"}, {40, "XL"}, {400, "CD"},
         {900, "CM"}};
        while (num) {
            if (num / 1000 >= 1) {
                ans += romans.find(1000)->second;
                num -= 1000;
            } else if (num / 900 >= 1) {
                ans += romans.find(900)->second;
                num -= 900;
            } else if (num / 100 >= 5) {
                ans += romans.find(500)->second;
                num -= 500;
            } else if (num / 100 == 4) {
                ans += romans.find(400)->second;
                num -= 400;
            } else if (num / 100 >= 1) {
                ans += romans.find(100)->second;
                num -= 100;                
            } else if (num / 90 >= 1) {
                ans += romans.find(90)->second;
                num -= 90;                
            } else if (num / 50 >= 1) {
                ans += romans.find(50)->second;
                num -= 50;                
            } else if (num / 40 >= 1) {               
                ans += romans.find(40)->second;
                num -= 40;                
            } else if (num / 10 >= 1) {
                ans += romans.find(10)->second;
                num -= 10;                 
            } else if (num / 9 >= 1) {
                ans += romans.find(9)->second;
                num -= 9;                 
            } else if (num / 5 >= 1) {
                ans += romans.find(5)->second;
                num -= 5;                 
            } else if (num / 4 >= 1) {
                ans += romans.find(4)->second;
                num -= 4;                 
            } else {
                ans += romans.find(1)->second;
                num -= 1;                
            }
        }
        return ans;        
    }
};
