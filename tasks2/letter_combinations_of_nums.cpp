/*
https://leetcode.com/problems/letter-combinations-of-a-phone-number/
*/
class Solution {
public:
    unordered_map<char, vector<string>> mapper = {
        {'2', vector<string>({"a", "b", "c"})},
        {'3', vector<string>({"d", "e", "f"})},
        {'4', vector<string>({"g", "h", "i"})},
        {'5', vector<string>({"j", "k", "l"})},
        {'6', vector<string>({"m", "n", "o"})},
        {'7', vector<string>({"p", "q", "r", "s"})},
        {'8', vector<string>({"t", "u", "v"})},
        {'9', vector<string>({"w", "x", "y", "z"})}
    };
    void conbine(string& digits, vector<string>& elems, string elem, int index) {
        if (index >= digits.size() && digits.size()) {
            elems.push_back(elem);
        } else {
            for (auto letter : mapper[digits[index]]) {
                conbine(digits, elems, elem + letter, index + 1);
            }
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> elems;
        conbine(digits, elems, "", 0);
        return elems;
    }
};
