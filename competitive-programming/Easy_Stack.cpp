#include <iostream>
#include <stack>

using namespace std;

void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void push_op(stack<int> &s)
{
    int n;
    cin >> n;
    s.push(n);
}

void pop_op(stack<int> &s)
{
    if (!s.empty())
        s.pop();
}

void print_top_op(stack<int> &s)
{
    if (s.empty())
        cout << "Empty!\n";
    else
        cout << s.top() << '\n';
}

void solve()
{
    int num_queries;
    cin >> num_queries;

    stack<int> s;
    int operation;

    while (num_queries--)
    {
        cin >> operation;

        switch (operation)
        {
        case 1:
            push_op(s);
            break;
        case 2:
            pop_op(s);
            break;
        case 3:
            print_top_op(s);
            break;
        }
    }
}

int main()
{
    fast_io();

    solve();
    return 0;
}