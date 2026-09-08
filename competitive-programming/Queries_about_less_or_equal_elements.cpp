#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
void Fast_IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<int> ReadVectorAndSort(int size)
{
    vector<int> v(size, 0);
    for (int i = 0; i < size; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    return v;
}

int find_upper_bound_index(const vector<int> &v, int target)
{
    int ans = -1;
    int left = 0, right = (int)v.size() - 1;
    while (left <= right)
    {
        int mid = midpoint(left, right);
        if (v[mid] <= target)
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return ans + 1;
}

void Solve()
{
    int size_a, queries_count;
    cin >> size_a >> queries_count;

    vector<int> v1 = ReadVectorAndSort(size_a);
    int target;
    while (queries_count--)
    {
        cin >> target;
        cout << find_upper_bound_index(v1, target) << ' ';
    }
    cout << '\n';
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