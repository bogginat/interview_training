/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/

Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> chars_used;
        auto it_from = s.begin();
        auto it_to = s.begin();
        int max_length = 0;
        while (it_to != s.end()) {
            if (chars_used.find(*it_to) == chars_used.end()) {
                chars_used.insert(*it_to);
                if (max_length < (it_to - it_from + 1)) {
                    max_length = it_to - it_from + 1;
                }
            } else {
                while (*it_from != *it_to) {
                    chars_used.erase(*it_from);
                    ++it_from;  
                }
                ++it_from;
            }
            ++it_to;
        }
        return max_length;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, size_t> chars_used;
        auto it_from = s.begin();
        auto it_to = s.begin();
        int max_length = 0;
        while (it_to != s.end()) {
            auto it_prev = chars_used.find(*it_to);
            if (it_prev != chars_used.end() &&
                it_prev->second >= it_from - s.begin()) {
                it_from = s.begin() + chars_used[*it_to] + 1;
            }
            chars_used[*it_to] = it_to - s.begin();
            max_length = max(max_length, static_cast<int>(std::distance(it_from, it_to)) + 1);
            ++it_to;
        }
        return max_length;
    }
};
