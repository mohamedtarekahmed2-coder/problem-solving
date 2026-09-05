#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<int> read_vector(int count)
{
    vector<int> v(count + 1, 0);
    for (int i = 1; i <= count; i++)
        cin >> v.at(i);
    return v;
}

int build_difference_array(vector<ll> &diff_array, vector<int> &num_theorems, vector<int> &type_behavior, int space)
{
    int ans = 0, range = (int)type_behavior.size() - space;
    for (int i = 1; i < (int)type_behavior.size(); i++)
    {
        if (type_behavior.at(i))
            ans += num_theorems.at(i);
        else
        {
            diff_array.at(i) += num_theorems.at(i);
            if (i < range)
                diff_array.at(i + space) -= num_theorems.at(i);
        }
    }
    return ans;
}

int get_ans(vector<ll> &diff_array)
{
    int val = 0, max_ans = 0;
    for (int i = 1; i < (int)diff_array.size(); i++)
    {
        val += diff_array.at(i);
        if (val > max_ans)
            max_ans = val;
    }
    return max_ans;
}

int main()
{
    fast_io();

    int dur_lec, min_awake;
    cin >> dur_lec >> min_awake;
    vector<int> num_theorems = read_vector(dur_lec);
    vector<int> type_behavior = read_vector(dur_lec);
    vector<ll> diff_array(dur_lec + 1, 0);
    int ans = build_difference_array(diff_array, num_theorems, type_behavior, min_awake);
    ans += get_ans(diff_array);
    cout << ans << '\n';

    return 0;
}