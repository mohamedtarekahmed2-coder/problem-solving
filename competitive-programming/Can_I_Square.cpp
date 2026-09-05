#include <iostream>
using namespace std;
using ll = long long;
void Fast_IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void Solve()
{
    int size;
    cin >> size;
    ll sum = 0;
    int num;
    for (int i = 0; i < size; i++)
    {
        cin >> num;
        sum += num;
    }

    ll left = 1, right = 1e9;
    while (left <= right)
    {
        ll mid = left + (right - left) / 2;
        if (sum == mid * mid)
        {
            cout << "YES\n";
            return;
        }
        else if (sum < mid * mid)
        {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    cout << "NO\n";
}

int main()
{
    Fast_IO();

    int test_cases = 1;
    cin >> test_cases;
    while (test_cases--)
    {
        Solve();
    }
    return 0;
}