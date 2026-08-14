#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void Fast_IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void Solve()
{
    int size_array, num_colors;
    cin >> size_array >> num_colors;
    vector<int> colors(size_array, 0);
    for(int &i : colors) cin >> i;

    vector<int> first_occur(num_colors + 1, 0);
    vector<int> last_occur(num_colors + 1, 0);

    for (int i = 0; i < colors.size(); i++)
    {
        if(first_occur[colors[i]] == 0)
        {
            first_occur[colors[i]] = i + 1;
            last_occur[colors[i]] = i + 1;
        }
        else 
        {
            last_occur[colors[i]] = i + 1;
        }
    }
    
    vector<int> answer (num_colors + 1, 0);
    int min_first = size_array + 1, max_last = 0;
    for (int i = num_colors; i >= 1; i--)
    {
        if(first_occur[i])
        {
            min_first = min(min_first, first_occur[i]);
            max_last = max(max_last, last_occur[i]);

            if(min_first != size_array + 1)
                answer[i] = (max_last - min_first + 1) * 2;
        }
    }
    
    for (int i = 1; i < answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }
    
    cout << '\n';
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