#include <iostream>
#include <set>
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main()
{
    fast_io();

    string name;
    cin >> name;
    set <char> letters;
    for (char &ch : name)
        letters.insert(ch);
    (letters.size() % 2 == 0)? cout << "CHAT WITH HER!\n" : cout << "IGNORE HIM!\n";

    return 0;
}