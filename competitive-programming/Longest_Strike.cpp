#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

struct Range
{
    int left;
    int right;
    int length = 0; 
};

vector<int> get_frequent_elements(int input_size, int min_frequency)
{
    unordered_map<int, int> frequency_map;
    for (int i = 0; i < input_size; i++)
    {
        int num;
        cin >> num;
        frequency_map[num]++;
    }
    
    vector<int> valid_elements;
    for (auto [num, count] : frequency_map)
        if (count >= min_frequency) 
            valid_elements.push_back(num);

    sort(valid_elements.begin(), valid_elements.end());
    return valid_elements;
}

void solve()
{
    int size, min_frequency;
    cin >> size >> min_frequency;

    vector<int> nums = get_frequent_elements(size, min_frequency);

    if (nums.empty())
    {
        cout << "-1\n";
        return;
    }

    Range best_range = {nums[0], nums[0], 0};
    int current_left = nums[0];
    int current_right = nums[0];

    for (size_t i = 0; i + 1 < nums.size(); i++)
    {
        if (nums[i] == nums[i + 1] - 1)
            current_right = nums[i + 1];
        else 
            current_left = current_right = nums[i + 1];

        int current_length = current_right - current_left;
        if (best_range.length < current_length)
        {
            best_range.length = current_length;
            best_range.left = current_left;
            best_range.right = current_right;
        }
    }
    cout << best_range.left << ' ' << best_range.right << '\n';
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
