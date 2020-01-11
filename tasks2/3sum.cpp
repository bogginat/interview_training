/*
https://leetcode.com/problems/3sum/
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) {
            return vector<vector<int>>{};
        }
        sort(nums.begin(), nums.end());
        if (nums.front() == nums.back() && nums.front() == 0) {
            return vector<vector<int>>{vector<int>{0, 0, 0}};
        }
        unordered_map<int, int> diff_from_zero(nums.size());
        set<vector<int>> set_ans; 
        for (size_t i = 0; i < nums.size(); ++i) {
            for (size_t j = i; j < nums.size(); ++j) {
                if (diff_from_zero.find(nums[j]) == diff_from_zero.end()) {
                    diff_from_zero[nums[j]] = j;
                }
                if (i == j) {
                    continue;
                }
                if (diff_from_zero.find(0 - nums[i] - nums[j]) != diff_from_zero.end() &&
                   i < j && diff_from_zero[0 - nums[i] - nums[j]] < i) {
                    set_ans.insert(vector<int>{nums[diff_from_zero[0 - nums[i] - nums[j]]], nums[i], nums[j]});
                }
            }
        }
        vector<vector<int>> ans(set_ans.begin(), set_ans.end());
        return ans;
    }
};
