#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * @lc app=leetcode id=3904 lang=cpp
 *
 * [3904] Smallest Stable Index II
 */

// @lc code=start
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> prefix_max(nums.size() + 1, 0);
        vector<int> suffix_min(nums.size() + 1, INT_MAX);

        for (int i = suffix_min.size() - 2; i >= 0; i--)
        {
            suffix_min[i] = min(suffix_min[i + 1], nums[i]);
        }

        for (int i = 1; i < prefix_max.size(); i++)
        {
            prefix_max[i] = max(prefix_max[i - 1], nums[i - 1]);
            int current = prefix_max[i] - suffix_min[i - 1];
            if (current <= k)
                return i - 1;
        }
        return -1;
    }
};
// @lc code=end

