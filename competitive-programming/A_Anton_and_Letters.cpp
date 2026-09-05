#include <iostream>
#include <set>
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve()
{
    string line;
    getline(cin, line);

    set<char> unique_letters;
    for (int i = 1; i < line.size() && line.at(i) != '}'; i+=3)
        unique_letters.insert(line.at(i));
    
    cout << unique_letters.size() << '\n';
}

int main()
{
    fast_io();

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}
