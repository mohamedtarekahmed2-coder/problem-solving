#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<int> ReadVector(int size)
{
    vector<int> v(size, 0);
    for (int &i : v)
        cin >> i;
    return v;
}

int GetMaxNum(const vector<int> &v)
{
    int size = v.size();
    int max_num_students = 0;
    for (int i = 0; i < size; i++)
    {
        int target = v[i] + 5;
        int left = i, right = size - 1, current_diff = 0;
        while (left <= right)
        {
            int mid = midpoint(left, right);
            if(v[mid] <= target)
            {
                current_diff = mid - i + 1;
                max_num_students = max(max_num_students, current_diff);
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
    }
    return max_num_students;
}

void solve()
{
    int size; 
    cin >> size;
    vector<int> v = ReadVector(size);
    sort(v.begin(), v.end());

    cout << GetMaxNum(v) << '\n';
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