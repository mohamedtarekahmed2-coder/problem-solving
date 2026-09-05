#include <iostream>
#include <algorithm>
using namespace std;

void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve()
{
    int loop;
    cin >> loop;
    int left = -2e9, right = 2e9;

    string op;
    int num;
    char ans;
    while (loop--)
    {
        cin >> op >> num >> ans;
        if (op == "<=")
        {
            if (ans == 'Y')
            {
                right = min(right, num);
            }
            else
            {
                left = max(left, num + 1); 
            }
        }
        else if (op == "<")
        {
            if (ans == 'Y')
            {
                right = min(right, num - 1);
            }
            else
            {
                left = max(left, num);
            }
        }
        else if (op == ">=")
        {
            if (ans == 'Y')
            {
                left = max(left, num);
            }
            else
            {
                right = min(right, num - 1);
            }
        }
        else if (op == ">")
        {
            if (ans == 'Y')
            {
                left = max(left, num + 1);
            }
            else
            {
                right = min(right, num);
            }
        }
    }
    
    if (left <= right) 
    {
        cout << left << '\n';
    }
    else
    {
        cout << "Impossible\n";
    }
}

int main()
{
    fast_io();

    int test_cases = 1;
    // cin >> test_cases;
    while (test_cases--)
    {
        solve();
    }

    return 0;
}