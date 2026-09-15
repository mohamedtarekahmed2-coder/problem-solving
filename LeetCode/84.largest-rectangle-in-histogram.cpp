#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int max_area = 0;
        stack<pair<int, int>> stack;
        for (int i = 0; i < ssize(heights); i++)
        {
            int start = i;
            while (!stack.empty() && stack.top().first > heights[i])
            {
                start = stack.top().second;
                int area = stack.top().first * (i - stack.top().second);
                max_area = max(max_area, area);
                stack.pop();
            }
            stack.push({heights[i], start});
        }
        while (!stack.empty())
        {
            int area = stack.top().first * (ssize(heights) - stack.top().second);
            max_area = max(max_area, area);
            stack.pop();
        }
        return max_area;
    }
};
// @lc code=end
