#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> hash_map_freq;
        vector<vector<int>> freq_buckets(nums.size() + 1);
        vector<int> answer(k, 0);

    }
};
// @lc code=end
