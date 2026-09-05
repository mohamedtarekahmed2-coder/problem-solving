#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void read_map(unordered_map<int, int> &freq_map, int total_elements)
{
    int num;
    for (int i = 0; i < total_elements; i++)
    {
        cin >> num;
        freq_map[num]++;
    }
}

void calc_max_kept(unordered_map<int, int> &nums_freq, vector<int> &freqs, int &max_kept)
{
    int current_kept = 0;
    for (auto freq : nums_freq)
        freqs.push_back(freq.second);
    sort(freqs.begin(), freqs.end());
    for (int i = 0; i < (int)freqs.size(); i++)
    {
        current_kept = freqs[i] * ((int)freqs.size() - i);
        if (max_kept < current_kept)
            max_kept = current_kept;
    }
}

void print_answer(int size, int max_kept)
{    
    int ans = size - max_kept;
    cout << ans << '\n';
}

void solve()
{
    int total_elements, num;
    cin >> total_elements;
    unordered_map<int, int> nums_freq;
    vector<int> freqs;
    
    read_map(nums_freq, total_elements);

    int max_kept = 0;
    calc_max_kept(nums_freq, freqs, max_kept);
    
    print_answer(total_elements, max_kept);
}

int main()
{
    fast_io();

    int test_cases = 1;
    cin >> test_cases;
    while (test_cases--)
        solve();

    return 0;
}