#include <iostream>
using namespace std;
using ll = long long;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

bool solve()
{
    ll num;
    cin >> num;
    while (num % 2 == 0)
        num /= 2;
    if (num > 1) return true;
    return false;
}

int main()
{
    fast_io();

    int test_cases = 1;
    cin >> test_cases;
    while (test_cases--)
    {
        if (solve())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}