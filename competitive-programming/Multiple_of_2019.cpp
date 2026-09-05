#include <iostream>
#include <vector>
#include <map>
using namespace std;

void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

long long Answer(const string &s)
{
    vector<int> nums((int)s.size() + 1, 0);
    map<int, int> diff;
    diff[0] = 1; 

    int index = 1;
    long long pow = 1; 
    
    for (int i = (int)s.size() - 1; i >= 0; i--)
    {
        nums[index] = (nums[index - 1] + ((s[i] - '0') * pow)) % 2019;
        diff[nums[index]]++;
        index++;
        pow = (pow * 10) % 2019; 
    }
    
    long long answer = 0;
    for(auto [a,b] : diff)
    {
        answer += (1LL * b * (b - 1)) / 2;
    }
    return answer;
}

void solve()
{
    string num = "";
    cin >> num;
    cout << Answer(num) << '\n';
}

int main()
{
    fast_io();

    int test_cases = 1;
    // cin >> test_cases;
    while (test_cases--)
    {
        solve();
    }

    return 0;
}