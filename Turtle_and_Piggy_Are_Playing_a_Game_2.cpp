#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<int> ReadVector(int size)
{
    vector<int> v(size, 0);
    for(int &i:v) 
        cin >> i;
    return v;
}

void solve()
{
    int size; cin >> size;
    vector<int> v = ReadVector(size);

    int index = size / 2;
    //Only sort the elements to get this index.
    nth_element(v.begin(), v.begin() + index, v.end());

    cout << v[index] << '\n';
}
 
int main()
{
    fast_io();

    int test_cases = 1;
    cin >> test_cases;
    while (test_cases--)
    {
        solve();
    }

    return 0;
}