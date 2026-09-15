#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
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
    int boss_health, attacks_num;
    cin >> boss_health >> attacks_num;
    vector<int> attacks_damage(attacks_num);
    vector<int> attacks_cooldown(attacks_num);
    copy_n(istream_iterator<int>(cin), attacks_num, attacks_damage.begin());
    copy_n(istream_iterator<int>(cin), attacks_num, attacks_cooldown.begin());

    ll left = 0, right = 1e11, min_turns = 1e11;
    while (left <= right)
    {
        ll mid = midpoint(left, right);
        ll count_damage = 0;
        for (int i = 0; i < attacks_num; i++)
        {
            count_damage += attacks_damage[i] * ((mid / attacks_cooldown[i]) + 1);
            if (boss_health <= count_damage) break;
        }
        if (boss_health <= count_damage) 
        {
            min_turns = mid + 1;
            right = mid - 1;
        }
        else 
        {
            left = mid + 1;
        }
    }
    cout << min_turns << '\n';
}

int main()
{
    fast_io();

    int test_cases = 1;
    cin >> test_cases;
    while (test_cases--)
    {
        solve();
    }
    return 0;
}