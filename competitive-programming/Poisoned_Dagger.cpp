#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
using ll = long long;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<int> read_vector(int size)
{
    vector<int> v(size);
    for (int i = 0; i < size; i++)
    {
        cin >> v[i];
    }
    return v;
}

ll total_damage(const vector<int> &v, ll time_test)
{
    ll count = time_test;
    for (int i = ssize(v) - 2; i >= 0 ; i--)
    {
        if(v[i] + time_test > v[i + 1])
            count += v[i + 1] - v[i];
        else 
            count += time_test;
    }
    return count;
}

void solve()
{
    int attacks_num;
    ll amount_of_damage;
    cin >> attacks_num >> amount_of_damage;
    vector<int> time_attacks = read_vector(attacks_num);

    ll left = 1, right = amount_of_damage, answer = LONG_LONG_MAX;
    while (left <= right)
    {
        ll mid = midpoint(left, right);
        ll current_damage = total_damage(time_attacks, mid);
        if(current_damage >= amount_of_damage)
        {
            answer = min(answer, mid);
            right = mid - 1;
        }
        else 
            left = mid + 1;
    }
    cout << answer << '\n';
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