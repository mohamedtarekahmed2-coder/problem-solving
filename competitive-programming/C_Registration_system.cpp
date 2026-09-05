#include <iostream>
#include <map>
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void new_name(map<string, int> &names, string &name)
{
    names.insert({name, 0});
    cout << "OK\n";
}

void old_name(map<string, int> &names, string &name)
{
    int num = ++names[name];
    cout << name << num << '\n';
}

int main()
{
    fast_io();

    int test_cases = 1;
    cin >> test_cases;
    map<string, int> names;
    string log_in_name;

    while (test_cases--)
    {
        cin >> log_in_name;
        if (names.count(log_in_name))
            old_name(names, log_in_name);
        else
            new_name(names, log_in_name);
    }

    return 0;
}