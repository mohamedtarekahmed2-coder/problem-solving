#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
void Fast_IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<int> ReadVector(int size)
{
    vector<int> v(size, 0);
    for(int &i : v) cin >> i;
    return v;
}

void Solve()
{
    int size;
    cin >> size;
    vector<int> nums = ReadVector(size);
    map<int, int> mp;
    
    int left = 0, answer = 1;
    int num_max = nums[0], num_min = nums[0];

    for (int right = 0; right < nums.size(); right++)
    {
        mp[nums[right]]++;
        num_max = max(num_max, nums[right]);
        num_min = min(num_min, nums[right]);
        while(num_max - num_min > 1 && left < right)
        {
            mp[nums[left]]--;
            left++;
            if(mp[num_min] == 0)
                num_min++;
            if(mp[num_max] == 0)
                num_max--;
        }
        answer = max(answer, right - left + 1);
    }
    cout << answer << '\n';
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