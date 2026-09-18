#include <iostream>
#include <unordered_set>
using namespace std;
/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> freq_chars;
        int left = 0, right = 0, res = 0;
        while (right < ssize(s))
        {
            char ch = s[right];
            
            while (freq_chars.contains(ch))
            {
                freq_chars.erase(s[left]);
                left++;
            }
            freq_chars.insert(ch);

            res = max(res, right - left + 1);
            right++;
        }
        return res;
    }
};
// @lc code=end
