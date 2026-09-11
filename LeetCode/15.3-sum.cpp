#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> triplets;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < (int)nums.size(); i++)
        {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1, right = ssize(nums) - 1;
            int current_sum = 0;
            while (left < right)
            {
                current_sum = nums[i] + nums[left] + nums[right];
                if (current_sum == 0)
                {
                    triplets.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                }
                else if (current_sum < 0)
                    left++;
                else
                    right--;
            }
        }
        return triplets;
    }
};
// @lc code=end
