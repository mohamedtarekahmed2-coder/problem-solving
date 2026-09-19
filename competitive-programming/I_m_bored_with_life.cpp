#include <iostream>
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve()
{
    int a, b; cin >> a >> b;
    int ans = min(a, b);
    int count = 1;
    for (int i = 2; i <= ans; i++)
        count *= i;
    cout << count << '\n';
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