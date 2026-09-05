#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void Fast_IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<int> ReadPrefixSum(int size)
{
    vector<int> v(size);
    for (int i = 0; i < size; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<int>());
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += v[i];
        v[i] = sum;
    }
    return v;
}

void Solve()
{
    int num_candies, queries;
    cin >> num_candies >> queries;
    vector<int> v = ReadPrefixSum(num_candies);
    
    int quantity_sugar;
    while (queries--)
    {
        cin >> quantity_sugar;
        int left = 0, right = num_candies - 1, answer = -1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (quantity_sugar <= v[mid])
            {
                answer = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        if (answer != -1)
            cout << answer + 1 << '\n';
        else
            cout << answer << '\n';
    }
}

int main()
{
    Fast_IO();

    int test_cases = 1;
    cin >> test_cases;
    while (test_cases--)
    {
        Solve();
    }
    return 0;
}