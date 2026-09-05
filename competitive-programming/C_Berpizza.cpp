#include <iostream>
#include <queue>
#include <vector>
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

struct custom_sort
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    }
};

struct solver 
{
    queue<int> mono; 
    priority_queue<pair<int, int>, vector<pair<int, int>>, custom_sort> poly;
    vector <bool> served;
    solver(int num_queries)
    {
        served.assign(num_queries + 1, false);
    }

    void take_customer(int customer, int money)
    {
        mono.push(customer);
        poly.push({money, customer});
    }
    
    void print_mono()
    {
        while (true)
        {
            if (served.at(mono.front()))
                mono.pop();
            else {
                cout << mono.front() << ' ';
                served.at(mono.front()) = true;
                mono.pop();
                break;
            }
        }
    }
    
    void print_poly()
    {
        while (true)
        {
            if (served.at(poly.top().second))
                poly.pop();
            else {
                cout << poly.top().second << ' ';
                served.at(poly.top().second) = true;
                poly.pop();
                break;
            }
        }
    }
};

int main()
{
    fast_io();

    int num_queries, customer = 1, operation, money;
    cin >> num_queries;

    solver solve(num_queries);

    while (num_queries--)
    {
        cin >> operation;
        switch (operation)
        {
        case 1:
            cin >> money;
            solve.take_customer(customer, money);
            customer++;
            break;
        case 2:
            solve.print_mono();
            break;
        default:
            solve.print_poly();
            break;
        }
    }
    cout << '\n';

    return 0;
}