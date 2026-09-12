#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int res = 0;
        int left = 0, right = 0;
        while (right < ssize(prices))
        {
            if(prices[right] > prices[left])
                res = max(res, prices[right] - prices[left]);
            else 
                left = right;
            right++;
        }
        return res;
    }
};
// @lc code=end
