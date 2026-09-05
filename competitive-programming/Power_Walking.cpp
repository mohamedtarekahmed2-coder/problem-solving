#include <iostream>
#include <set>
using namespace std;

void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

set<int> read_set(int size)
{
    set<int> s;
    int val;
    while (size--)
    {
        cin >> val;
        s.insert(val);
    }
    return s;
}

void print_answer (int num_types, int num_powers)
{
    int val = num_types;
    for (int i = 1; i <= num_powers; i++)
    {
        if (i > num_types)
            cout << ++val << ' ';
        else
            cout << val << ' ';
    }
    cout << '\n';
}

void solve()
{
    int num_powers;
    cin >> num_powers;

    set<int> power_types = read_set(num_powers);

    int num_types = static_cast<int>(power_types.size());

    print_answer(num_types, num_powers);
}

int main()
{
    fast_io();

    int test_cases = 1;
    cin >> test_cases;
    while (test_cases--)
        solve();

    return 0;
}