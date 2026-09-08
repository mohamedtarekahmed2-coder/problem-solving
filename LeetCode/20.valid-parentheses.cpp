#include <iostream>
#include <stack>
using namespace std;
/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        char ch, topStack;
        for (int i = 0; i < s.size(); i++)
        {
            ch = s[i];
            if (!st.empty())
            {
                topStack = st.top();
                if ((topStack == '(' && ch == ')') || (topStack == '{' && ch == '}') || (topStack == '[' && ch == ']'))
                {
                    st.pop();
                }
                else
                {
                    st.push(ch);
                }
            }
            else
            {
                st.push(ch);
            }
        }
        if (st.empty())
            return true;
        return false;
    }
};
// @lc code=end
