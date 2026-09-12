#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;
using ll = long long;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve()
{
    int total_population;
    cin >> total_population;
    vector<int> wealths(total_population);
    copy_n(istream_iterator<int>(cin), total_population, wealths.begin());

    if(ssize(wealths) < 3)
    {
        cout << -1 << '\n';
        return;
    }

    sort(wealths.begin(), wealths.end());

    ll count = 0;
    for (int i = 0; i < ssize(wealths); i++)
        count += wealths[i];
    
    ll half_less_average = wealths[total_population / 2];
    ll current = (2LL * total_population * half_less_average) - count;
    
    cout << max(0LL, current + 1) << '\n';
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