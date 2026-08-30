#include <iostream>
#include <vector>
#include <algorithm>
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

void Solve()
{
    int num_shops;
    cin >> num_shops;
    vector<int> prices = ReadVectorAndSort(num_shops);
    int days;
    cin >> days;
    while (days--)
    {
        int total_shops = 0, coins = 0;
        cin >> coins;
        int left = 0, right = num_shops - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (prices[mid] <= coins)
            {
                total_shops = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }

            if (left > right)
            {
                total_shops = left;
            }
        }
        cout << total_shops << '\n';
    }
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