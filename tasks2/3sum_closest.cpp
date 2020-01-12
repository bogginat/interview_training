/*
https://leetcode.com/problems/3sum-closest/
*/

class Solution {
    void SetMinDiff(vector<int>::iterator closest,
                    int& min_difference, int num,
                    vector<int>& diff_vector,
                    int index,
                    unordered_map<int, pair<int, int>>& diff_to_index) {
        auto closest_index = diff_to_index.find(*closest);
        if (closest_index == diff_to_index.end() ||
            closest_index->second.first == index ||
            closest_index->second.second == index) {
            return;
        }
        if (closest != diff_vector.end() &&
            abs(min_difference) > abs(*closest - num)) {
            min_difference = *closest - num;
        }        
    }
    
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int min_difference = INT_MAX;
        unordered_map<int, pair<int, int>> diff_to_index;
        vector<int> diff_vector;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (i == j) {
                    continue;
                }
                auto value = target - (nums[i] + nums[j]);
                diff_to_index[value] = make_pair(i, j);
                diff_vector.push_back(value);
            }
        }
        sort(diff_vector.begin(), diff_vector.end());
        for (int i = 0; i < nums.size(); ++i) {
            auto closest = lower_bound(
                diff_vector.begin(), diff_vector.end(), nums[i]);
            SetMinDiff(closest, min_difference, nums[i],
                       diff_vector, i, diff_to_index);
            if (closest == diff_vector.begin()) {
                continue;
            }
            --closest;
            SetMinDiff(closest, min_difference, nums[i],
                       diff_vector, i, diff_to_index);
        }
        return target - min_difference;
    }
};
