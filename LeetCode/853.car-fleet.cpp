#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode id=853 lang=cpp
 *
 * [853] Car Fleet
 */

// @lc code=start
class Solution
{
public:
    int carFleet(int target,vector<int> &position, vector<int> &speed)
    {
        vector<pair<int, int>> position_speed;
        for (int i = 0; i < position.size(); i++)
        {
            position_speed.push_back({position[i], speed[i]});
        }
        sort(position_speed.rbegin(), position_speed.rend());

        stack<float> st;
        for (int i = 0; i < position_speed.size(); i++)
        {
            float time_to_end = (float)(target - position_speed[i].first) / position_speed[i].second;
            if(st.empty())
                st.push(time_to_end);
            else if(st.top() < time_to_end)
            {
                st.push(time_to_end);
            }
        }
        return st.size();
    }
};
// @lc code=end

int main()
{
    Solution s;
    // cout << s.carFleet(13, {10,2,5,7,4,6,11}, {7,5,10,5,9,4,1}) << '\n';
    return 0;
}