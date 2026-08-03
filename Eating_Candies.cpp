#include <iostream>
#include <vector>
using namespace std;
void FastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<int> ReadVector(int size)
{
    vector<int> v(size, 0);
    for (int &i : v)
    {
        cin >> i;
    }
    return v;
}

void solve()
{
    int size;
    cin >> size;
    vector<int> candy_weights = ReadVector(size);

    int left = 0, right = size - 1;
    int left_sum = candy_weights[left], right_sum = candy_weights[right];
    int answer = 0;

    while (left < right)
    {
        if (left_sum == right_sum)
        {
            answer = (left + 1) + (size - right);
            left++;
            right--;
            left_sum += candy_weights[left];
            right_sum += candy_weights[right];
        }
        else if (left_sum < right_sum)
        {
            left++;
            left_sum += candy_weights[left];
        }
        else if (left_sum > right_sum)
        {
            right--;
            right_sum += candy_weights[right];
        }
    }

    cout << answer << '\n';
}

int main()
{
    FastIO();

    int test_cases = 1;
    cin >> test_cases;
    while (test_cases--)
    {
        solve();
    }

    return 0;
}