#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
        {
            return false;
        }

        unordered_map<char, int> s_freq;
        unordered_map<char, int> t_freq;
        for (int i = 0; i < s.size(); i++)
        {
            s_freq[s[i]]++;
            t_freq[t[i]]++;
        }

        for (auto [key, val] : s_freq)
        {
            if(val != t_freq[key])
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

