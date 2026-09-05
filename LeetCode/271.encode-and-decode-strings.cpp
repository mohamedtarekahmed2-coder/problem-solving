#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string encode(vector<string> &strs)
    {
        string answer = "";
        for (int i = 0; i < strs.size(); i++)
        {
            answer += to_string(strs[i].size()) + "#" + strs[i];
        }
        return answer;
    }

    vector<string> decode(string s)
    {
        vector<string> answer;
        int i = 0;
        while (i < s.size())
        {
            int length = 0;
            while(s[i] != '#')
            {
                length *= 10;
                length += s[i] - '0';
                i++;
            }
            i++;
            answer.push_back(move(s.substr(i, length)));
            i += length;
        }
        return answer;
    }
};

int main()
{
    vector<string> v = {""};
    Solution s;
    string ss = s.encode(v);
    vector<string> ans = s.decode(ss);
    for(string i : ans)
    {
        cout << i << ' ';
    }
    return 0;
}