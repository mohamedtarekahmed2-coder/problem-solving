#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>
using namespace std;
using ll = long long;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve()
{
    int ingredients_n, magic_powder_g;
    cin >> ingredients_n >> magic_powder_g;
    vector<int> grams_needed(ingredients_n);
    copy_n(istream_iterator<int>(cin), ingredients_n, grams_needed.begin());
    vector<int> grams_has(ingredients_n);
    copy_n(istream_iterator<int>(cin), ingredients_n, grams_has.begin());

    ll left = 0, right = 2e9, answer = 0;
    while (left <= right)
    {
        ll mid = midpoint(left, right);
        ll count = 0, cal = 0;
        for (int i = 0; i < ingredients_n; i++)
        {
            cal = (grams_needed[i] * mid) - grams_has[i];
            if (cal > 0)
                count += cal;
            if(count > magic_powder_g) break;
        }

        if(count <= magic_powder_g)
        {
            answer = mid;
            left = mid + 1;
        }
        else 
            right = mid - 1;
    }
    cout << answer << '\n';
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