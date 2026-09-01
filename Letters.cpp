#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
void Fast_IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<ll> ReadPrefixSum(ll size)
{
    vector<ll> v(size);
    ll sum = 0, num = 0;
    for (ll i = 0; i < size; i++)
    {
        cin >> num;
        sum += num;
        v[i] = sum;
    }
    return v;
}

pair<ll, ll> FindRoom(const vector<ll> &v)
{
    ll position; cin >> position;
    pair <ll, ll> ans;
    ll left = 0, right = v.size() - 1;
    while (left <= right)
    {
        ll mid = left + (right - left) / 2;
        if(v[mid] >= position)
        {
            ans.first = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    ans.second = position;
    if (ans.first) 
        ans.second -= v[ans.first - 1];
    ans.first += 1;
    return ans;
}

void Solve()
{
    ll size, letters;
    cin >> size >> letters;
    vector<ll> v = ReadPrefixSum(size);

    while (letters--)
    {
        auto answer = FindRoom(v);
        cout << answer.first << ' ' << answer.second << '\n';
    }
}

signed main()
{
    Fast_IO();

    ll test_cases = 1;
    // cin >> test_cases;
    while (test_cases--)
    {
        Solve();
    }
    return 0;
}