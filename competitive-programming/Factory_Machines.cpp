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
    int machines_num, products_num;
    cin >> machines_num >> products_num;
    vector<int> machines_time(machines_num);
    copy_n(istream_iterator<int>(cin), machines_num, machines_time.begin());
    
    ll left = 0, right = 1e18, min_time_needed = 1e18;
    while (left <= right)
    {
        ll mid = midpoint(left, right);
        ll producted = 0;
        for (ll i : machines_time)
        {
            producted += mid / i;
            if (products_num <= producted) break;
        }
        if (products_num <= producted)
        {
            min_time_needed = mid;
            right = mid - 1;
        }
        else 
        {
            left = mid + 1;
        }
    }
    cout << min_time_needed << '\n';
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