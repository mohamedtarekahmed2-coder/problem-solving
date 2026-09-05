#include <iostream>
#include <vector>
#include <map>

using namespace std;
using ll = long long;

void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<ll> ReadVector(int count)
{
    vector<ll> v(count + 1, 0);

    for (int i = 1; i < v.size(); i++)
        cin >> v[i];

    return v;
}

void BuildPrefix(vector<ll> &v)
{
    for (int i = 1; i < v.size(); i++)
        v[i] += v[i - 1];
}

ll GetAnswer(const vector<ll> &v, int target)
{
    ll answer = 0;

    map<ll, int> is_here;
    is_here[v[0]] = 1;
    for (int i = 1; i < v.size(); i++)
    {
        ll diff = v[i] - target;
        auto pre = is_here.find(diff);
        if(pre != is_here.end())
            answer += pre->second;
        is_here[v[i]]++;
    }

    return answer;
}

void solve()
{
    int size, target;
    cin >> size >> target;

    vector<ll> elements = ReadVector(size);
    BuildPrefix(elements);

    cout << GetAnswer(elements, target) << '\n';
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