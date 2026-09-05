#include <iostream>
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve(const string &students, int size)
{
    int answer = 0, max_time = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        if (students[i] == 'P')
            max_time++;
        else if (answer < max_time)
        {
            answer = max_time;
            max_time = 0;
        }
        else
            max_time = 0;
    }
    cout << answer << '\n';
}

int main()
{
    fast_io();
    int test_cases, str_size;
    string students;
    cin >> test_cases;
    while (test_cases--)
    {
        cin >> str_size >> students;
        solve(students, str_size);
    }

    return 0;
}