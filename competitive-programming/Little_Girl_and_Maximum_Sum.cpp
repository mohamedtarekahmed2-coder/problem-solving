#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<int> read_and_sort_vector(int count)
{
    vector<int> v(count, 0);
    for (int &i : v)
        cin >> i;

    sort(v.begin(), v.end(), greater<int>());
    return v;
}

vector<int> build_frequency_vector(int size, int count)
{
    vector<int> v(size + 2, 0);
    int from, to;

    for (int i = 0; i < count; i++)
    {
        cin >> from >> to;
        v[from]++;
        v[to + 1]--;
    }

    for (int i = 1; i < v.size(); i++)
        v[i] += v[i - 1];

    sort(v.begin(), v.end(), greater<int>());
    return v;
}

void solve()
{
    int num_elements, num_queries;
    cin >> num_elements >> num_queries;

    vector<int> elements = read_and_sort_vector(num_elements);
    vector<int> highest_repeat = build_frequency_vector(num_elements, num_queries);

    ll answer = 0;
    for (int i = 0; i < num_elements; i++)
        answer += (ll)elements[i] * (ll)highest_repeat[i];

    cout << answer << '\n';
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