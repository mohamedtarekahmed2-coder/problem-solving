#include <iostream>
#include <vector>
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<int> prefix_xor(int num_values)
{
    vector<int> pre_xor(num_values + 1, 0);

    int value;
    for (int i = 1; i < (int)pre_xor.size(); i++)
    {
        cin >> value;
        pre_xor[i] = pre_xor[i - 1] ^ value;
    }

    return pre_xor;
}

int main()
{
    fast_io();
    int num_values, num_queries;
    cin >> num_values >> num_queries;

    vector<int> pre_xor = prefix_xor(num_values);

    int start, end;
    while (num_queries--)
    {
        cin >> start >> end;
        cout << (pre_xor[end] ^ pre_xor[start - 1]) << '\n';
    }

    return 0;
}