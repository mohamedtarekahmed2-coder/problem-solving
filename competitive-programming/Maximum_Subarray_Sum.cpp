#include <iostream>
#include <climits>
#include <vector>
using ll = long long;
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<ll> prefix_sum(int size){
    vector<ll> v(size, 0);

    ll sum = 0, num;
    for (int i = 0; i < size; i++)
    {
        cin >> num;
        sum += num;
        v[i] = sum;
    }
    
    return v;
}

void answer(const vector<ll>& pre_sum)
{
    ll max_sum = 0, min_before_max = 0;
    ll answer = LLONG_MIN;
    for (int i = 0; i < (int) pre_sum.size(); i++)
    {
        max_sum = pre_sum[i] - min_before_max;
        if (max_sum > answer)
            answer = max_sum;
        if(pre_sum[i] < min_before_max)
            min_before_max = pre_sum[i];
    }
    cout << answer << '\n';
}

void solve()
{
    int size_array;
    cin >> size_array;

    vector<ll> pre_sum = prefix_sum(size_array);

    answer(pre_sum);
}

int main()
{
    fast_io();

    int test_cases = 1;
    while (test_cases--)
    {
        solve();
    }

    return 0;
}