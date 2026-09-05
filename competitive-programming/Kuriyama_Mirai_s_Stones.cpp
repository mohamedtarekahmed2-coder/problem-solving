#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<ll> read_vector(int size, int start = 0)
{
    vector<ll> v(size, 0);

    for (int i = start; i < size; i++)
        cin >> v[i];

    return v;
}

template <typename T>
vector<T> build_prefix(int size, vector<T> &v)
{
    vector<T> pre(size + 1, 0);

    for (int i = 1; i < (int)pre.size(); i++)
        pre[i] = pre[i - 1] + v[i];

    return pre;
}

template <typename T>
void answer_prefix(vector<T> &vec, int start, int end)
{
    cout << vec[end] - vec[start - 1] << '\n';
}

int main()
{
    fast_io();
    int num_costs;
    cin >> num_costs;

    vector<ll> costs = read_vector(num_costs + 1, 1);

    vector<ll> pre_cost = build_prefix(num_costs, costs);

    sort(costs.begin() + 1, costs.end());
    costs = build_prefix(num_costs, costs);

    int num_questions, question_type, start, end;
    cin >> num_questions;

    while (num_questions--)
    {
        cin >> question_type >> start >> end;
        if (question_type == 1)
            answer_prefix(pre_cost, start, end);
        else
            answer_prefix(costs, start, end);
    }

    return 0;
}