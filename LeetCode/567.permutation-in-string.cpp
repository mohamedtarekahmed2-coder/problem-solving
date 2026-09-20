#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        if (ssize(s1) > ssize(s2))
            return false;

        vector<int> s1Count(26, 0);
        vector<int> s2Count(26, 0);

        for (int i = 0; i < ssize(s1); i++)
        {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }

        int matches = 0;
        for (int i = 0; i < 26; i++)
            if (s1Count[i] == s2Count[i])
                matches++;

        int left = 0;
        for (int right = ssize(s1); right < ssize(s2); right++)
        {
            if (matches == 26)
                return true;

            int index = s2[right] - 'a';
            s2Count[index]++;
            if (s2Count[index] == s1Count[index])
                matches++;
            else if (s1Count[index] + 1 == s2Count[index])
                matches--;

            index = s2[left] - 'a';
            s2Count[index]--;
            if (s2Count[index] == s1Count[index])
                matches++;
            else if (s1Count[index] - 1 == s2Count[index])
                matches--;
            left++;
        }
        return matches == 26;
    }
};
// @lc code=end
