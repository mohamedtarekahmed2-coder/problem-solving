#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> num_index;
        for (int i = 0; i < nums.size(); i++)
        {
            int new_target = target - nums[i];
            auto it = num_index.find(new_target);
            if (it != num_index.end())
            {
                return {it->second, i};
            }
            num_index[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end
