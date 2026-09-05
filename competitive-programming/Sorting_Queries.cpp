#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void append (queue <int> &queries){
    int query;
    cin >> query;
    queries.push(query);
}

void print_front_sort_or_not(queue <int> &queries, priority_queue<int,vector<int>, greater<int>> &q_sorted){
    if (!q_sorted.empty()){
        cout << q_sorted.top() << '\n';
        q_sorted.pop();
    }
    else{
        cout << queries.front() << '\n';
        queries.pop();
    }
}

void sort_from_q_to_pq(queue <int> &queries, priority_queue<int,vector<int>, greater<int>> &q_sorted){
    while (!queries.empty()){
        q_sorted.push(queries.front());
        queries.pop();
    }
}

void solve (int num_queries){
    queue <int> queries;
    priority_queue <int,vector<int>, greater<int>> queries_sorted;
    int operation;
    while (num_queries--)
    {
        cin >> operation;
        switch (operation)
        {
        case 1:
            append(queries);
            break;
        case 2:
            print_front_sort_or_not(queries, queries_sorted);
            break;
        case 3:
            sort_from_q_to_pq(queries, queries_sorted);
            break;
        }
    }
}

int main()
{
    fast_io();

    int num_queries;
    cin >> num_queries;
    solve(num_queries);

    return 0;
}