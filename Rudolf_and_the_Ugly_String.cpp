#include <iostream>
#include <string>

using namespace std;

void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve()
{
    int size;
    cin >> size;
    string s;
    cin >> s;

    int answer = 0;
    int pointer = 0; 

    while (pointer < size)
    {
        if (pointer + 4 < size && s.substr(pointer, 5) == "mapie")
        {
            answer++;
            pointer += 5; 
        }
        else if (pointer + 2 < size && s.substr(pointer, 3) == "map")
        {
            answer++;
            pointer += 3;
        }
        else if (pointer + 2 < size && s.substr(pointer, 3) == "pie")
        {
            answer++;
            pointer += 3;
        }
        else
            pointer++;
    }

    cout << answer << '\n';
}

int main()
{
    fast_io();

    int test_cases = 1;
    cin >> test_cases;
    while (test_cases--)
    {
        solve();
    }

    return 0;
}