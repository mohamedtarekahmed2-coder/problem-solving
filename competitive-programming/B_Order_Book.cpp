#include <iostream>
#include <map>
#include <vector>
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void add_new_or_old(map<int, int, greater<int>> &direction)
{
    int price, volume;
    cin >> price >> volume;

    if (direction.count(price))
        direction[price] += volume;
    else 
        direction.insert({price, volume});
}

void add_new_or_old(map<int, int> &direction)
{
    int price, volume;
    cin >> price >> volume;

    if (direction.count(price))
        direction[price] += volume;
    else 
        direction.insert({price, volume});
}

void print_answer_B(map<int, int, greater<int>> &direction, char ch, int depth)
{
    for (auto it = direction.begin(); it != direction.end() && depth; it++)
    {
        cout << ch << ' ' << it->first << ' ' << it->second << '\n';
        depth--;
    }
}

void print_answer_S(map<int, int> &direction, char ch, int depth)
{   
    vector<pair<int, int>> v;
    for (auto it = direction.begin(); it != direction.end() && depth; it++)
    {
        v.push_back({it->first, it->second});
        depth--;
    }
    for (auto it = v.rbegin(); it != v.rend(); it++)
    {
        cout << ch << ' ' << it->first << ' ' << it->second << '\n';
    }
}

void solve(int num_order, int depth_book)
{
    map<int, int, greater<int>> B_direction;
    map<int, int> S_direction;
    char ch;
    for (int i = 0; i < num_order; i++)
    {
        cin >> ch;
        if (ch == 'B')
            add_new_or_old(B_direction);
        else 
            add_new_or_old(S_direction);
    }
    print_answer_S(S_direction, 'S', depth_book);
    print_answer_B(B_direction, 'B', depth_book);
}

int main()
{
    fast_io();

    int num_order, depth_book;
    cin >> num_order >> depth_book;
    solve(num_order, depth_book);

    return 0;
}