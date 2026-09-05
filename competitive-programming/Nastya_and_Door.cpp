#include <iostream>
#include <vector>
#include <climits>
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<int> prefix_sum(int size)
{
    vector<int> v(size, 0);
    
    for(int &element : v) cin >> element;

    return v;
}

vector<int> prefix_height(const vector<int> &heights)
{
    vector<int> pre_height((int)heights.size(), 0);
    
    for (int i = 1; i < (int)heights.size(); i++)
    {
        pre_height[i] += pre_height[i - 1];
        if((i < (int)heights.size() - 1) && heights[i - 1] < heights[i] && heights[i] > heights[i + 1])
        {
            pre_height[i]++;
        }
    }
    
    return pre_height;
}

void answer(const vector<int> &pre_height, int length_door)
{
    int space = length_door - 2;
    int max_mountains = INT_MIN, left_border = 0;

    for (int i = 0; i < (int)pre_height.size() - space; i++)
    {
        int mountains = pre_height[i + space] - pre_height[i];
        if(mountains > max_mountains){
            max_mountains = mountains;
            left_border = i + 1;
        }
    }
    cout << max_mountains + 1 << ' ' << left_border<< '\n';
}

void solve()
{
    int num_mountains, length_door;
    cin >> num_mountains >> length_door;

    vector<int> heights_mountains = prefix_sum(num_mountains);
    vector<int> pre_heights = prefix_height(heights_mountains);

    answer(pre_heights, length_door);
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