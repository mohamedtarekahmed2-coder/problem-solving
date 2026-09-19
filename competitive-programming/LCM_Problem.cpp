#include <iostream>
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve()
{
    int left, right; cin >> left >> right;
    int x = left, y = 2 * x;
    if (y > right) cout << -1 << ' ' << -1 << '\n';
    else cout << x << ' ' << y << '\n';
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