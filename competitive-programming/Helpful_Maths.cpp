#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void extract_numbers(string &s, vector<int> &nums)
{
    for (int i = 0; i < (int)s.size(); i++)
        if (s[i] != '+')
            nums.push_back(s[i] - '0');
}

void sort_numbers(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
}

void print_answer(vector<int> &nums)
{

    for (int i = 0; i < (int)nums.size(); i++)
    {
        cout << nums[i];
        if (i != (int)nums.size() - 1)
            cout << "+";
    }
    cout << '\n';
}

void solve()
{
    string s;
    cin >> s;
    
    vector<int> nums;
    
    extract_numbers(s, nums);
    sort_numbers(nums);
    print_answer(nums);
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