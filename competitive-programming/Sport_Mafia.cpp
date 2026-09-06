#include <iostream>
#include <numeric>
using namespace std;
using ll = long long;
void Fast_IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}


void Solve()
{
    int total_moves, target_candies;
    cin >> total_moves >> target_candies;

    int left = 0, right = total_moves, ans = 0;
    while (left <= right)
    {
        int mid = midpoint(left, right);
        ll added_candies_steps = total_moves - mid;
        ll total_candies_added = (added_candies_steps * (added_candies_steps + 1)) / 2;
        ll current_candies_count = total_candies_added - mid;
        if(current_candies_count == target_candies)
        {
            ans = mid;
            break;
        }
        else if (current_candies_count > target_candies)
        {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    cout << ans << '\n';
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