#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void print_map(unordered_map <string,string> & mp)
{
    cout << mp.size() << '\n';
    for (const auto& [key, val] : mp)
        cout << key << ' ' << val << '\n';
}

void solve(int count)
{
    unordered_map <string, string> old_new;
    unordered_map <string, string> new_old;
    string s_old, s_new;
    for (int i = 0; i < count; i++)
    {
        cin >> s_old >> s_new;
        if(!new_old.count(s_old))
        {
            old_new[s_old] = s_new;
            new_old[s_new] = s_old;
        }
        else
        {
            old_new[new_old[s_old]] = s_new;
            new_old[s_new] = new_old[s_old];
        }
    }
    print_map(old_new);
}


int main()
{
    fast_io();

    int test_cases = 1;
    cin >> test_cases;
    solve(test_cases);

    return 0;
}