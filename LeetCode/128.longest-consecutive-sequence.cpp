#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_map<int, int> hash_map;

        int res = 0;
        for (auto i : nums)
        {
            if (!hash_map[i])
            {
                hash_map[i] = hash_map[i + 1] + hash_map[i - 1] + 1;
                hash_map[i + hash_map[i + 1]] = hash_map[i];
                hash_map[i - hash_map[i - 1]] = hash_map[i];
                res = max(hash_map[i], res);
            }
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << s.longestConsecutive(nums) << '\n';
    return 0;
}