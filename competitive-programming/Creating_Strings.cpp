#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void creating_strings(vector<string> &strs_created, string &target, string &str_end)
{
    // The end case
    if (target == str_end)
        return;

    int size = target.size();
    int ch1, ch2;

    // To know the decrease point
    for (int i = size - 1; i > 0; --i)
    {
        if (target[i] > target[i - 1])
        {
            ch1 = i - 1;
            break;
        }
    }

    // To know the first point more then decrease point
    for (int i = size - 1; i > 0; --i)
    {
        if (target[i] > target[ch1])
        {
            ch2 = i;
            break;
        }
    }

    // Swap (ch1 and ch2) and reverse from ch1 to end
    swap(target[ch1], target[ch2]);
    reverse(target.begin() + ch1 + 1, target.end());

    // Store and call
    strs_created.push_back(target);
    creating_strings(strs_created, target, str_end);
}

int main()
{
    string str;
    cin >> str;

    // Make vector to store the strings
    vector<string> strs_created;

    // Make normal Sort and Greater Sort to Know start and end
    string str_sorted = str;
    sort(str_sorted.begin(), str_sorted.end());
    string str_sorted_greater = str;
    sort(str_sorted_greater.begin(), str_sorted_greater.end(), greater<char>());

    // Normal sort is the first string
    strs_created.push_back(str_sorted);

    creating_strings(strs_created, str_sorted, str_sorted_greater);

    // Print number of strings and strings
    cout << strs_created.size() << '\n';
    for (int i = 0; i < strs_created.size(); i++)
        cout << strs_created.at(i) << '\n';

    return 0;
}
