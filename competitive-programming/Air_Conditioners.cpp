#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using ll = long long;
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<int> read_vector(int count)
{
    vector<int> v(count, 0);
    for (int &element : v)
        cin >> element;
    return v;
}

unordered_map<int, int> read_map(const vector<int> &air_positions)
{
    unordered_map<int, int> mp;
    int temperature;
    for (int element : air_positions)
    {
        cin >> temperature;
        mp[element] = temperature;
    }
    return mp;
}

vector<ll> build_prefix_temp(const unordered_map<int, int> &positions_temp, int size)
{
    vector<ll> pre_temp(size + 1, 0);

    for (int i = 1; i < pre_temp.size(); i++)
    {
        if (auto it = positions_temp.find(i); it != positions_temp.end()&& (pre_temp[i - 1] == 0 || it->second < pre_temp[i - 1] + 1))
            pre_temp[i] = it->second;
        else if(pre_temp[i-1] != 0)
            pre_temp[i] = pre_temp[i-1] + 1;
    }

    return pre_temp;
}

vector<ll> build_suffix_temp(const unordered_map<int, int> &positions_temp, int size)
{
    vector<ll> suf_temp(size + 1, 0);

    for (int i = suf_temp.size() - 2; i >= 0; i--)
    {
        if (auto it = positions_temp.find(i + 1); it != positions_temp.end() && (suf_temp[i + 1] == 0 || it->second < suf_temp[i + 1] + 1))
            suf_temp[i] = it->second;
        else if(suf_temp[i + 1] != 0)
            suf_temp[i] = suf_temp[i + 1] + 1;
    }

    return suf_temp;
}

void print_answer(const vector<ll> &pre_temp, const vector<ll> &suf_temp)
{
    int ans;
    for (int i = 1; i < pre_temp.size(); i++)
    {
        ans = min(pre_temp[i], suf_temp[i - 1]);
        if(ans == 0)
            ans = max(pre_temp[i], suf_temp[i - 1]);
        cout << ans << ' ';
    }
    
    cout << '\n';
}

void solve()
{
    int length_strip_land, num_air_conditioners;
    cin >> length_strip_land >> num_air_conditioners;

    vector<int> air_positions = read_vector(num_air_conditioners);

    unordered_map<int, int> positions_temperatures = read_map(air_positions);

    vector<ll> pre_temp = build_prefix_temp(positions_temperatures, length_strip_land);
    vector<ll> suf_temp = build_suffix_temp(positions_temperatures, length_strip_land);

    print_answer(pre_temp, suf_temp);
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