#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
void Fast_IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<pair<int, int>> ReadPairVector(int size)
{
    vector<pair<int, int>> v;
    v.reserve(size);
    int first_e, second_e;
    while (size--)
    {
        cin >> first_e >> second_e;
        v.push_back({first_e, second_e});
    }

    return v;
}

vector<ll> PrefixSum(vector<pair<int, int>> &v)
{
    ll sum = 0;
    vector<ll> pre_sum(v.size() + 1, 0);
    for (int i = 1; i < pre_sum.size(); i++)
    {
        sum += v[i - 1].second;
        pre_sum[i] = sum;
    }

    return pre_sum;
}

void Solve()
{
    int num_friends, min_diff;
    cin >> num_friends >> min_diff;

    vector<pair<int, int>> money_friendship = ReadPairVector(num_friends);
    sort(money_friendship.begin(), money_friendship.end());
    vector<ll> pre_sum = PrefixSum(money_friendship);

    int left = 0;
    ll answer = 0, current_answer = 0;

    for (int right = 0; right < num_friends; right++)
    {
        while (money_friendship[right].first - money_friendship[left].first >= min_diff)
        {
            left++;
        }

        current_answer = pre_sum[right + 1] - pre_sum[left];
        answer = max(answer, current_answer);
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