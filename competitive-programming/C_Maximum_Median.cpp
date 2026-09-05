#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
void Fast_IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<ll> ReadVectorAndSort(ll size)
{
    vector<ll> v(size);
    for (ll i = 0; i < size; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    return v;
}

bool can(ll mid, const vector<ll> &v, ll chances)
{
    ll sum = 0;
    for (int i = v.size() / 2; i < v.size(); i++)
    {
        if (v[i] < mid)
        {
            sum += mid - v[i];
        }
    }
    return sum <= chances;
}

ll BinarySearch(const vector<ll> &elements, ll size, ll chances)
{
    ll left = elements[size / 2], right = elements[size / 2] + chances, answer = 0;
    while (left <= right)
    {
        ll mid = (left + right) / 2;
        if (can(mid, elements, chances))
        {
            answer = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return answer;
}

void Solve()
{
    ll size, chances;
    cin >> size >> chances;
    vector<ll> elements = ReadVectorAndSort(size);

    cout << BinarySearch(elements, size, chances) << '\n';
}

int main()
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