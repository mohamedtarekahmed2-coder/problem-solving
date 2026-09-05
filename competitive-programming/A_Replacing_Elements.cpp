#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n, d;
    cin >> n >> d;
    int a[n];
    bool all_under = true;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > d)
            all_under = false;
    }

    if (all_under)
    {
        cout << "YES" << endl;
        return;
    }

    sort(a, a + n);

    (a[0] + a[1] <= d) ? cout << "YES\n" : cout << "NO\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}