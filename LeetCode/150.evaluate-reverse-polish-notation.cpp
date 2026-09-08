#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */
// @lc code=start
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int first_num, second_num, result;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                second_num = st.top();
                st.pop();
                first_num = st.top();
                st.pop();
                if (tokens[i] == "+")
                    result = first_num + second_num;
                else if (tokens[i] == "-")
                    result = first_num - second_num;
                else if (tokens[i] == "*")
                    result = first_num * second_num;
                else
                    result = first_num / second_num;
                st.push(result);
            }
            else
            {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
// @lc code=end
