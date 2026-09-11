#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int total_water = 0;
        int left = 0, right = (int)height.size() - 1, left_max = 0, right_max = 0;
        while (left <= right)
        {
            left_max = max(left_max, height[left]);
            right_max = max(right_max, height[right]);
            total_water += left_max - height[left] + right_max - height[right];
            if(height[left] < height[right])
                left++;
            else 
                right--;
        }
        return total_water;
    }
};
// @lc code=end
