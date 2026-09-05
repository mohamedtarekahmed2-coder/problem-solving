#include <iostream>
#include <vector>
using namespace std;
using ll = long long ;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<int> build_prefix(const string &s)
{
    vector<int> v(s.size(), 0);
    int sum = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '+')
            sum++;
        else
            sum--;
        v[i] = sum;
    }
    return v;
}

void solve()
{
    string s;
    cin >> s;
    ll res = s.size();

    vector<int> pre_sum = build_prefix(s);
    int cur = 0;
    for (int i = 0; i < pre_sum.size(); i++)
    {
        if (cur + pre_sum[i] < 0)
        {
            res += (i + 1);
            cur++;
        }
    }
    cout << res << '\n';
}

int main()
{
    fast_io();

    int test_cases = 1;
    cin >> test_cases;
    while (test_cases--)
    {
        solve();
    }

    return 0;
}