#include <iostream>
#include <vector>
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

/**
 * make prefix sum of S(i) = S(i+1)
 * subtract pre_sum[r - 1] - pre_sum[l]
 */

vector<int> make_pre_sum(const string &s)
{
    int count = (int)s.size();
    vector<int> sum(count, 0);
    for (int i = 1; i < count; i++)
        sum[i] = sum[i - 1] + (int)(s[i - 1] == s[i]);
    return sum;
}

int main()
{
    fast_io();
    string s;
    cin >> s;
    vector<int> sum = make_pre_sum(s);
    int test_cases = 1, l, r;
    cin >> test_cases;
    while (test_cases--)
    {
        cin >> l >> r;
        cout << sum[r - 1] - sum[l - 1] << '\n';
    }

    return 0;
}