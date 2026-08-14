#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
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
    sort(elements.begin(), elements.end(), greater<int>());
    
    int answer = 0;
    int left_start = 0, left_end = size / 2;
    int right_start = size / 2, right_end = size;
    
    while((left_start < left_end) && (right_start < right_end))
    {
        if(elements[left_start] >= elements[right_start] * 2)
        {
            left_start++;
            right_start++;
            answer++;
        }
        else
        {
            right_start++;
            answer++;
        }
    }
    answer += (left_end - left_start) + (right_end - right_start);
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