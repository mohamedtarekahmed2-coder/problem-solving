#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = ssize(nums) - 1;
        while (left < right)
        {
            int mid = midpoint(left, right);
            if (nums[mid] > nums[right])
            {
                left = mid + 1;
            }
            else 
            {
                right = mid;
            }
        }
        return nums[left];
    }
};
// @lc code=end

