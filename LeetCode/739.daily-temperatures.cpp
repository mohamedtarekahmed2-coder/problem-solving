#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        vector<int> daysToWait(n, 0);
        stack<int> indexStack;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!indexStack.empty() && temperatures[indexStack.top()] <= temperatures[i])
            {
                indexStack.pop();
            }
            if (!indexStack.empty())
                daysToWait[i] = indexStack.top() - i;
            indexStack.push(i);
        }
        return daysToWait;
    }
};
// @lc code=end
