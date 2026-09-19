#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int left = 1, right = *max_element(piles.begin(), piles.end()), result = right;
        while (left <= right)
        {
            int mid = midpoint(left, right);
            int count_h = 0;
            for (int i = 0; i < ssize(piles); i++)
            {
                count_h += (piles[i] + mid - 1) / mid;
                if (count_h > h) break;
            }
            if (count_h <= h)
            {
                result = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        return result;
    }
};
// @lc code=end
