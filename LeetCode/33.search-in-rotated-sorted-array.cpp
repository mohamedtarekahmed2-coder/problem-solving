#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0, right = ssize(nums) - 1;
        while (left <= right)
        {
            int mid = midpoint(left, right);
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[left] <= nums[mid])
            {
                if (nums[left] <= target && target < nums[mid])
                {
                    right = mid - 1;
                }
                else 
                {
                    left = mid + 1;
                }
            }
            else 
            {
                if (nums[mid] < target && target <= nums[right])
                {
                    left = mid + 1;
                }
                else 
                {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};
// @lc code=end
