#include <iostream>
#include <queue>
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

struct operation
{
    string op_type;
    int num;
};

struct priority_queue_manager
{
    priority_queue<int, vector<int>, greater<int>> heap_sorted;
    queue<operation> seq_op;

    void process_insert(int num)
    {
        heap_sorted.push(num);
        seq_op.push({"insert", num});
    }

    void process_remove()
    {
        if (heap_sorted.empty())
            process_insert(1);
        heap_sorted.pop();
        seq_op.push({"removeMin", 0});
    }

    void process_get(int num)
    {
        while (true)
        {
            if (heap_sorted.empty() || num < heap_sorted.top())
                process_insert(num);

            else if (num == heap_sorted.top())
            {
                seq_op.push({"getMin", num});
                break;
            }
            else
                process_remove();
        }
    }

    void print_operations()
    {
        cout << seq_op.size() << '\n';
        int count = static_cast<int>(seq_op.size());
        for (int i = 0; i < count; i++)
        {
            cout << seq_op.front().op_type;
            if (!(seq_op.front().op_type == "removeMin"))
                cout << ' ' << seq_op.front().num;
            cout << '\n';
            seq_op.pop();
        }
    }
};

int main()
{
    fast_io();

    priority_queue_manager manager;

    int num_op, num = 0;
    string op;
    cin >> num_op;

    while (num_op--)
    {
        cin >> op;
        if (op == "insert")
        {
            cin >> num;
            manager.process_insert(num);
        }
        else if (op == "removeMin")
            manager.process_remove();
        else
        {
            cin >> num;
            manager.process_get(num);
        }
    }

    manager.print_operations();
    return 0;
}