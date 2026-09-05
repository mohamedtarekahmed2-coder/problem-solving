#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;
void Fast_IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

bool can(ll mid, ll candies)
{
    ll test = (mid * (mid + 1)) / 2;
    return test <= candies;
}

void Solve()
{
    ll candies;
    cin >> candies;
    /*
    ll left = 1, right = candies, answer = 0;
    while (left <= right)
    {
        ll mid = left + (right - left) / 2;
        if(can(mid, candies))
        {
            answer = mid;
            left = mid + 1;
        }
        else 
        {
            right = mid - 1;
        }
    }
    */
    // math form
    ll answer = (sqrt(1.0 + 8.0 * candies) - 1) / 2;
    cout << answer << '\n';
}

int main()
{
    Fast_IO();

    int test_cases = 1;
    // cin >> test_cases;
    while (test_cases--)
    {
        Solve();
    }
    return 0;
}