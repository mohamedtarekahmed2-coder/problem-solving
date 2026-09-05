#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}



//  * read vector of n prise 
void read_vector (vector <int> &v, int start = 0)
{
    for (int i = start; i < (int)v.size(); i++)
    cin >> v.at(i);
}

void make_pre_sum(vector <ll> &pre, vector <int> &v)
{
    //  * make prefix sum from 1 to end
    for (int i = 1; i < (int)pre.size(); i++)
    pre.at(i) = pre.at(i - 1) + v.at(i - 1);
}

void print_answer(vector <ll> &pre, int num_queries)
{
    int total_items, discount_items;
    while(num_queries--)
    {
        cin >> total_items >> discount_items;
        //  * answer for each buyer = pre[total_items] - pre[total_items - discount_items]
        cout << pre[total_items] - pre[total_items - discount_items] << '\n';
    }
}

int main()
{
    fast_io();
    
    //  * read n and q
    int num_items, num_queries;
    cin >> num_items >> num_queries;
    
    vector <int> item_prices (num_items, 0);
    read_vector(item_prices);
    
    //  * sort vector from Big to Small
    sort(item_prices.begin(), item_prices.end(), greater<int>());

    vector <ll> pre_sum (num_items + 1, 0);
    make_pre_sum(pre_sum, item_prices);

    print_answer(pre_sum, num_queries);

    return 0;
}