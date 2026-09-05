#include <iostream>
#include <queue>
#include <vector>
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void read_vector(vector<int> &vec, const int &count)
{
    for (int i = 0; i < count; i++)
        cin >> vec.at(i);
}

void solve(queue<int> &num_steps, const int &count)
{
    vector<int> all_steps(count + 1, 0);
    read_vector(all_steps, count);

    for (int i = 0; i < count; i++)
    {
        if (all_steps.at(i) >= all_steps.at(i + 1))
            num_steps.push(all_steps.at(i));
    }
}

void print_queue(queue<int> &q)
{
    int count = q.size();

    for (int i = 0; i < count; i++)
    {
        cout << q.front() << ' ';
        q.pop();
    }
    cout << '\n';
}

int main()
{
    fast_io();
    int total_steps;
    cin >> total_steps;

    queue<int> num_steps;
    solve(num_steps, total_steps);

    cout << num_steps.size() << '\n';
    print_queue(num_steps);

    return 0;
}