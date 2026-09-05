#include <iostream>
#include <vector>
using ll = long long;
using namespace std;
void Fast_IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<ll> PrefixSum(int size)
{
    vector<ll> v(size + 1, 0);
    ll sum = 0;
    int num;
    for (int i = 1; i < v.size(); i++)
    {
        cin >> num;
        sum += num;
        v[i] = sum;
    }
    
    return v;
}

void Solve()
{
    int size, target;
    cin >> size >> target;

    vector<ll> pre_sum = PrefixSum(size);

    int left = 0;
    int answer = 0;
    for (int right = 0; right < pre_sum.size(); right++)
    {
        while(pre_sum[right] - pre_sum[left] > target)
        {
            left++;
        }
        if(pre_sum[right] - pre_sum[left] == target) answer++;
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