#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;
using ll = long long;

struct ing
{
    ll bread;
    ll seg;
    ll cheese;
};

bool can_make(ll x, ing r_ing, ing n_ing, ing p_ing, ll r)
{
    ll reqB = max(0LL, x * r_ing.bread - n_ing.bread);
    ll reqS = max(0LL, x * r_ing.seg - n_ing.seg);
    ll reqC = max(0LL, x * r_ing.cheese - n_ing.cheese);

    ll totalCost = reqB * p_ing.bread + reqS * p_ing.seg + reqC * p_ing.cheese;
    return totalCost <= r;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string recipe;
    cin >> recipe;
    ing n_ing{}, p_ing{}, r_ing{0, 0, 0};
    cin >> n_ing.bread >> n_ing.seg >> n_ing.cheese;
    cin >> p_ing.bread >> p_ing.seg >> p_ing.cheese;
    ll r;
    cin >> r;

    for (char c : recipe)
    {
        if (c == 'B')
            r_ing.bread++;
        else if (c == 'S')
            r_ing.seg++;
        else
            r_ing.cheese++;
    }

    ll low = 0, high = 1e13, ans = 0;
    while (low <= high)
    {
        ll mid = midpoint(low, high);
        if (can_make(mid, r_ing, n_ing, p_ing, r))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << ans << "\n";
    return 0;
}