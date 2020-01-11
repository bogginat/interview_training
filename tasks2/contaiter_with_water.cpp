/*
https://leetcode.com/problems/container-with-most-water/

Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        size_t start = 0;
        size_t end = height.size() - 1;
        size_t area = 0;
        while(start < end) {
            area = max(area, size_t((end - start) * min(height[start], height[end])));
            if (height[start] < height[end]) {
                ++start;
            } else if (height[start] > height[end]) {
                --end;
            } else if (height[start + 1] < height[end - 1]) {
                ++start;
            } else {
                --end;
            }
        }
        return area;
    }
};
