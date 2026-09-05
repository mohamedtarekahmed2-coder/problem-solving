#include <iostream>
#include <vector>
#include <map>
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
    vector<int> elements = ReadVector(size);

    int answer = 0;
    map<int, int> mp;

    for(int i : elements)
        mp[i] = 0;

    int ptr1 = 0, ptr2 = 0;
    while(ptr2 < size)
    {
        if(mp[elements[ptr2]] == 0)
        {
            mp[elements[ptr2]]++;
            ptr2++;
        }
        else if(mp[elements[ptr2]] == 1)
        {
            mp[elements[ptr2]]++;
            while(mp[elements[ptr2]] == 2)
            {
                mp[elements[ptr1]]--;
                ptr1++;
            }
            ptr2++;
        }
        answer = max(answer, ptr2 - ptr1);
    }
    cout << answer << '\n';
}

int main()
{
    Fast_IO();

    int test_cases = 1;
    // cin >> test_cases;
    while (test_cases--)
    {
        Solve();
    }

    return 0;
}