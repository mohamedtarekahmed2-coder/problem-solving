#include <iostream>
#include <numeric>
using ll = long long;
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve()
{
    int divider, position;
    cin >> divider >> position;

    ll left = 1, right = LLONG_MAX, answer = 0;
    while (left <= right)
    {
        ll mid = midpoint(left, right);
        ll condition = mid - (mid / divider);
        if(condition == position)
        {
            answer = mid;
            right = mid - 1;
        }
        else if(condition < position)
            left = mid + 1;
        else
            right = mid - 1;
    }
    cout << answer << '\n';
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