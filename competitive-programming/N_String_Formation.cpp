#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int q = 1, rev = 0;
    cin >> s >> q;
    short ti, fi;
    char ch;
    deque<char> ans;
    for (char &i : s)
        ans.push_back(i);
    while (q--)
    {
        cin >> ti;
        if (ti == 1)
            rev++;
        else
        {
            cin >> fi >> ch;
            if (rev % 2 != 0)
                (fi == 1) ? fi = 2 : fi = 1;
            (fi == 1) ? ans.push_front(ch) : ans.push_back(ch);
        }
    }
    if (rev % 2 != 0)
        reverse(ans.begin(), ans.end());
    for (char &i : ans)
        cout << i;
    cout << "\n";
    return 0;
}