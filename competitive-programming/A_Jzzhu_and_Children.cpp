#include <iostream>
#include <queue>
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void read_queue(queue<pair<int, int>> &q, int count)
{
    int child;
    for (int i = 0; i < count; i++)
    {
        cin >> child;
        q.push({child, i + 1});
    }
}

void solve(queue<pair<int, int>> &children, int max)
{
    while (children.size() > 1)
    {
        if (children.front().first <= max)
            children.pop();
        else
        {
            children.push({children.front().first - max,
                           children.front().second});
            children.pop();
        }
    }
    cout << children.front().second << '\n';
}

int main()
{
    fast_io();

    int num_children, max_candies;
    cin >> num_children >> max_candies;

    queue<pair<int, int>> children;
    read_queue(children, num_children);

    solve(children, max_candies);
    return 0;
}