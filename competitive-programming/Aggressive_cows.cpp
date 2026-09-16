#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>

using namespace std;

bool can_place_cows(const vector<int> &stalls, int C, int min_dist)
{
    int count = 1;
    int last_pos = stalls[0];

    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - last_pos >= min_dist)
        {
            count++;
            last_pos = stalls[i];
        }
        if (count >= C)
            return true;
    }
    return false;
}

void solve()
{
    int N, C;
    cin >> N >> C;
    vector<int> stalls(N);
    copy_n(istream_iterator<int>(cin), N, stalls.begin());
    sort(stalls.begin(), stalls.end());

    int left = 1, right = stalls.back() - stalls.front(), ans = 0;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (can_place_cows(stalls, C, mid))
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t)
    {
        while (t--)
        {
            solve();
        }
    }
    return 0;
}