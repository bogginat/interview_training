/* 
https://leetcode.com/problems/two-sum/


Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, size_t> num_to_index;
        for (size_t i = 0; i < nums.size(); ++i) {
            const auto target_it = num_to_index.find(target - nums[i]);
            if (target_it != num_to_index.end()) {
                return vector<int>{target_it->second, i};
            }
            num_to_index[nums[i]] = i;
        }
        return vector<int>{0, 0};
    }
};
