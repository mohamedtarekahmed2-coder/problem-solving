#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> map;
        for (const string &s : strs)
        {
            vector<int> count(26, 0);
            for (char c : s)
            {
                count[c - 'a']++;
            }

            string key = "";
            for (int i = 0; i < 26; i++)
            {
                key += to_string(count[i]) + "#";
            }
            map[key].push_back(s);
        }

        vector<vector<string>> answer;
        for (auto &pair : map)
        {
            answer.push_back(move(pair.second));
        }
        return answer;
    }
};
// @lc code=end
