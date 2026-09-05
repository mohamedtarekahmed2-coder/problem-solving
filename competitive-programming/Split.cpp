#include <iostream>
#include <vector>
#include <map>
using namespace std;
void Fast_IO()
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

void Solve()
{
    int size, num_multisets;
    cin >> size >> num_multisets;
    vector<int> elements = ReadVector(size);
    map<int, int> mp_limits;
    map<int, int> mp_freq;

    for (int i = 0; i < size; i++)
    {
        mp_limits[elements[i]]++;
        mp_freq[elements[i]] = 0;
    }

    for (auto &[a, b] : mp_limits)
    {
        if (!(b % num_multisets))
        {
            b /= num_multisets;
        }
        else
        {
            cout << '0' << '\n';
            return;
        }
    }

    long long answer = 0;
    int left = 0, right = 0;
    while (right < size)
    {
        mp_freq[elements[right]]++;
        while (mp_freq[elements[right]] > mp_limits[elements[right]])
        {
            mp_freq[elements[left]]--;
            left++;
        }
        answer += right - left + 1;
        right++;
    }
    cout << answer << '\n';
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