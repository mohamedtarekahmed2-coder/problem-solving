#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void Fast_IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<int> ReadVector(int size)
{
    vector<int> v(size, 0);
    for(int &i : v)
        cin >> i;
    return v;
}
void Solve()
{
    int size;
    cin >> size;
    vector<int> v = ReadVector(size);

    int index = 1;
    while (true)
    {
        if (index == size - 1) break;
        else if (v[index - 1] >= 1 && v[index + 1] >= 1 && v[index] >= 2)
        {
            int diff = min(min(v[index - 1], v[index + 1]), v[index] / 2);
            v[index - 1]-= diff;
            v[index + 1]-= diff;
            v[index] -= 2 * diff;
        }
        else index++;
    }
    
    bool all_is_zeros = true;
    for(int i : v)
    {
        if (i != 0)
        {
            all_is_zeros = false;
            break;
        }
    }
    
    if (all_is_zeros)
        cout << "YES\n";
    else 
        cout << "NO\n";
}

int main()
{
    Fast_IO();

    int test_cases = 1;
    cin >> test_cases;
    while (test_cases--)
    {
        Solve();
    }

    return 0;
}