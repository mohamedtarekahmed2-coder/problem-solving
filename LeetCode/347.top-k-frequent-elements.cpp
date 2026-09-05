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
        unordered_map<int, int> hash_map;
        for (int &num : nums)
        {
            hash_map[num]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);
        for (auto pair : hash_map)
        {
            buckets[pair.second].push_back(pair.first);
        }

        vector<int> answer;
        for (int i = (int)buckets.size() - 1; i > 0; i--)
        {
            for (int j : buckets[i])
            {
                answer.push_back(j);
                if (answer.size() == k)
                    return answer;
            }
        }
        return answer;
    }
};
// @lc code=end
