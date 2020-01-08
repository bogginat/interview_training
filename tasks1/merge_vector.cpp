/*
https://leetcode.com/problems/median-of-two-sorted-arrays/submissions/


There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

template<typename T>
class MergeIterator {
public:
    using TIt = typename vector<T>::iterator;
    
    MergeIterator(vector<T>& nums1, vector<T>& nums2) {
        it1 = nums1.begin();
        it2 = nums2.begin();
        it1_end = nums1.end();
        it2_end = nums2.end();
    }
    
    TIt Next() {
        if (it1 != it1_end &&
            (it2 != it2_end && *it1 <= *it2 || it2 == it2_end)) {
            current = it1;
            ++it1;
        } else if (it2 != it2_end &&
                   (it1 != it1_end && *it1 > *it2 || it1 == it1_end)) {
            current = it2;
            ++it2;
        } else {
            current = it1_end;
        }
        return current;
    }
    
    T Get() {
        if (current == it1_end && current == it2_end) {
            throw std::runtime_error{"End of vector"};
        }
        return *current;
    }

private:
    TIt it1;
    TIt it2;
    TIt it1_end;
    TIt it2_end;
    TIt current;
};

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        MergeIterator<int> my_it(nums1, nums2);
        if (nums1.empty() && nums2.empty()) {
            return 0;
        }
        for (int i = 0; i < (nums1.size() + nums2.size()) / 2; ++i) {
            my_it.Next();
        }
        if ((nums1.size() + nums2.size()) % 2) {
            my_it.Next();
            return my_it.Get();
        }
        auto first = my_it.Get();
        my_it.Next();
        auto second = my_it.Get();
        return (static_cast<double>(first) + static_cast<double>(second)) / 2;
    }
};
