#include <iostream>
#include <queue>
using namespace std;

void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void read_queue(queue<int> &q, int count)
{
    int element;
    for (int i = 0; i < count; i++)
    {
        cin >> element;
        q.push(element);
    }
}

void print_queue(queue<int> &q)
{
    while (!q.empty())
    {
        cout << q.front() << ' ';
        q.pop();
    }
    cout << '\n';
}

void left_rotation(queue<int> &q, int num_rotation)
{
    while (num_rotation--)
    {
        q.push(q.front());
        q.pop();
    }
}

int main()
{
    fast_io();

    int size_queue, num_rotation;
    cin >> size_queue >> num_rotation;
    num_rotation %= size_queue;

    queue<int> numbers;
    read_queue(numbers, size_queue);
    left_rotation(numbers, num_rotation);
    print_queue(numbers);

    return 0;
}
