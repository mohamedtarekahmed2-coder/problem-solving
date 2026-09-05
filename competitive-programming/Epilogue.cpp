#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<int> BuildPrefixMax(int count)
{
    vector<int> pre_max(count + 1, 0);

    int num;
    for (int i = 1; i < count + 1; i++)
    {
        cin >> num;
        pre_max[i] = max(pre_max[i - 1], num);
    }

    return pre_max;
}

vector<int> ReadVector(int count)
{
    vector<int> v(count, 0);
    for (auto &i : v)
        cin >> i;
    return v;
}

void solve()
{
    int num_spells;
    cin >> num_spells;
    vector<int> influence_desmond = BuildPrefixMax(num_spells);
    vector<int> influence_thorwald = BuildPrefixMax(num_spells);

    int num_days;
    cin >> num_days;
    vector<int> seriousness_desmond = ReadVector(num_days);
    vector<int> seriousness_thorwald = ReadVector(num_days);

    for (int i = 0; i < num_days; i++)
    {
        auto it_desmond = upper_bound(influence_desmond.begin(), influence_desmond.end(), seriousness_desmond[i]);
        auto it_thorwald = upper_bound(influence_thorwald.begin(), influence_thorwald.end(), seriousness_thorwald[i]);

        int diff_desmond = (it_desmond != influence_desmond.end()) ? (it_desmond - influence_desmond.begin()) : 1e9;
        int diff_thorwald = (it_thorwald != influence_thorwald.end()) ? (it_thorwald - influence_thorwald.begin()) : 1e9;

        if (diff_desmond > diff_thorwald)
            cout << "Constantine\n";
        else if (diff_desmond < diff_thorwald)
            cout << "Mike\n";
        else
            cout << "Draw\n";
    }
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