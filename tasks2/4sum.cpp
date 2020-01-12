/*
https://leetcode.com/problems/4sum/
*/

class Solution {
    struct Hash {
       size_t operator()(const vector<int>& nums) const {
           string target = to_string(nums[0]) + "_" + to_string(nums[1]) + "_" +
               to_string(nums[2]) + "_" + to_string(nums[3]);
           return hash<string>()(target);
       }
    };
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        unordered_set<vector<int>, Hash> used_results;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 3; j < nums.size(); ++j) {
                int second = i + 1;
                int third = j - 1;
                while (second < third) {
                    int tmp_sum = nums[i] + nums[second] + nums[third] + nums[j];
                    if (tmp_sum < target) {
                        ++second;
                        continue;
                    }
                    if (tmp_sum > target) {
                        --third;
                        continue;
                    }
                    vector<int> tmp{nums[i], nums[second], nums[third], nums[j]};
                    if (used_results.find(tmp) == used_results.end()) {
                        used_results.insert(tmp);
                        result.push_back(tmp);
                    }
                    ++second;
                    --third;
                }
            }
        }
        return result;
    }
};
