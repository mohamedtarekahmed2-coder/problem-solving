#include <iostream>
#include <set>
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int solve(const string &s)
{
    int days_count = 1;
    set <char> unique_chars;
    for (char c : s)
    {
        unique_chars.insert(c);
        if (unique_chars.size() > 3)
        {
            unique_chars.clear();
            unique_chars.insert(c);
            days_count++;
        }
    }
    return days_count;
}

int main()
{
    fast_io();

    int test_cases = 1;
    cin >> test_cases;
    while (test_cases--)
    {
        string str;
        cin >> str;
        cout << solve(str) << '\n';
    }

    return 0;
}