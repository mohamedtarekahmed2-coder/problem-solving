#include <iostream>
#include <map>
#include <algorithm>
#include <climits>
using namespace std;
void Fast_IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void Solve()
{
    int num_flats;
    string input_string;
    cin >> num_flats >> input_string;

    map<char, int> char_frequency;
    for (char ch : input_string)
        char_frequency[ch] = 0;

    int left = 0;
    int answer = INT_MAX;
    int counter_unique_chars = 0;

    for (int right = 0; right < num_flats; right++)
    {
        char_frequency[input_string[right]]++;
        if (char_frequency[input_string[right]] == 1)
        {
            counter_unique_chars++;
        }
        if (counter_unique_chars >= char_frequency.size())
        {
            while (char_frequency[input_string[left]] > 1)
            {
                char_frequency[input_string[left]]--;
                left++;
            }
            answer = min(answer, right - left + 1);
        }
    }

    cout << answer << '\n';
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