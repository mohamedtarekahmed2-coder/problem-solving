#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int max_water = 0;
        int left = 0, right = static_cast<int>(height.size()) - 1;
        int current_area = 0;
        while (left < right)
        {
            current_area = min(height[left], height[right]) * (right - left);
            max_water = max(max_water, current_area);
            if(height[left] < height[right])
                left++;
            else 
                right--;
        }
        return max_water;
    }
};
// @lc code=end
