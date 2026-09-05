#include <iostream>
#include <map>
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

bool has_common_char (string &s1, string &s2)
{
    bool yes = false;
    multimap<char, bool> s1_chars;

    for (char &c : s1)
        s1_chars.insert({c, true});

    for (int i = 0; i < s2.size() && yes == false; i++)
        yes = s1_chars.count(s2.at(i));

    return yes;
}

int main()
{
    fast_io();

    int test_cases = 1;
    cin >> test_cases;
    while (test_cases--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        cout << (has_common_char(s1, s2) ? "YES" : "NO") << '\n';
    }

    return 0;
}