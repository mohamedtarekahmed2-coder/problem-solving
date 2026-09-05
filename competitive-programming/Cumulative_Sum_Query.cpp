#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main()
{
    fast_io();
    int size, sum = 0, val;
    vector<int> sums(1, 0);

    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cin >> val;
        sums.push_back(sums.at(i) + val);
    }

    int q; cin >> q;
    int i, j;
    while (q--)
    {
        cin >> i >> j;
        cout << sums[j + 1] - sums[i] << '\n';
    }

    return 0;
}