#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm> 

using namespace std;

void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<int> read_vector(int count)
{
    vector<int> v(count, 0);
    for (int &num : v)
        cin >> num;
    return v;
}

vector<int> get_prefix_gcd(const vector<int> &nums)
{
    int n = nums.size();
    vector<int> pre_gcd(n, 0);
    
    pre_gcd[0] = nums[0];
    for (int i = 1; i < n; i++)
        pre_gcd[i] = gcd(pre_gcd[i - 1], nums[i]);
    
    return pre_gcd;
}

vector<int> get_suffix_gcd(const vector<int> &nums)
{
    int n = nums.size();
    vector<int> suf_gcd(n, 0);
    
    suf_gcd[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--)
        suf_gcd[i] = gcd(suf_gcd[i + 1], nums[i]);
    
    return suf_gcd;
}

void solve()
{
    int size; 
    cin >> size;
    vector<int> nums = read_vector(size);

    vector<int> pre_gcd = get_prefix_gcd(nums);
    vector<int> suf_gcd = get_suffix_gcd(nums);

    int max_ans = max(pre_gcd[size - 2], suf_gcd[1]);
    
    for (int i = 0; i < size - 2; i++)
    {
        int current_gcd = gcd(pre_gcd[i], suf_gcd[i + 2]);
        max_ans = max(max_ans, current_gcd);
    }
    
    cout << max_ans << '\n';
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