#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<int> build_prefix_odds(int count)
{
    vector<int> pre(count + 1, 0);

    int num;
    for (int i = 1; i < (int)pre.size(); i++)
    {
        cin >> num;
        pre[i] = pre[i - 1] + ((num % 2) ? 1 : 0);
    }

    return pre;
}

long long fast_power(long long base, long long power, long long mod)
{
    long long result = 1;
    base = base % mod;
    while (power > 0)
    {
        if (power % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        power /= 2;
    }
    return result;
}

void solve()
{
    int num_elements, num_questions;
    cin >> num_elements >> num_questions;

    vector<int> prefix_odds = build_prefix_odds(num_elements);

    int start, end, type, space, num_odds;
    long long model = 1e9 + 7;

    while (num_questions--)
    {
        cin >> start >> end >> type;
        long long answer;
        num_odds = prefix_odds[end] - prefix_odds[start - 1];

        if (type == 0)
        {
            space = end - start + 1;
            long long p1 = fast_power(2, space, model);
            long long p2 = fast_power(2, num_odds, model);
            answer = (p1 - p2 + model) % model;
        }
        else
        {
            long long p1 = fast_power(2, num_odds, model);
            answer = (p1 - 1 + model) % model;
        }
        cout << answer << '\n';
    }
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