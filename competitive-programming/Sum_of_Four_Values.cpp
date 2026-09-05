#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

struct num_indexs
{
    long long num; 
    int index_one;
    int index_two;

    bool operator<(const num_indexs& other) const
    {
        return num < other.num; 
    }
};

vector<pair<long long, int>> read_elements(int size, long long target)
{
    long long element;
    vector<pair<long long, int>> v;
    for (int i = 0; i < size; i++)
    {
        cin >> element;
        if (element < target)
            v.push_back(make_pair(element, i + 1));
    }
    sort(v.begin(), v.end());
    return v;
}

void print(const vector<int> &ans)
{
    vector<int> sorted_ans = ans;
    sort(sorted_ans.begin(), sorted_ans.end());
    for (int i : sorted_ans)
        cout << i << ' ';
    cout << '\n';
}

void make_half(vector<pair<long long, int>> &v, vector<num_indexs> &half)
{
    for (int i = 0; i < (int)v.size(); i++)
        for (int l = i + 1; l < (int)v.size(); l++)
            half.push_back({v[i].first + v[l].first, v[i].second, v[l].second});
    sort(half.begin(), half.end());
}

void find_four_sum(vector<pair<long long, int>> &elements, long long target)
{
    vector<num_indexs> half;
    vector<int> ans;
    make_half(elements, half);

    for (int i = 0; i < (int)half.size(); i++)
    {
        long long needed_sum = target - half[i].num;
        num_indexs dummy;
        dummy.num = needed_sum;
        auto range = equal_range(half.begin() + i + 1, half.end(), dummy);
        
        for (auto it = range.first; it != range.second; ++it)
        {
            if (half[i].index_one != it->index_one &&
                half[i].index_one != it->index_two &&
                half[i].index_two != it->index_one &&
                half[i].index_two != it->index_two)
            {
                ans.push_back(half[i].index_one);
                ans.push_back(half[i].index_two);
                ans.push_back(it->index_one);
                ans.push_back(it->index_two);
                
                print(ans);
                return;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}

void solve()
{
    int element_size;
    long long target_num;
    cin >> element_size >> target_num;

    vector<pair<long long, int>> elements = read_elements(element_size, target_num);

    find_four_sum(elements, target_num);
}

int main()
{
    fast_io();

    int test_cases = 1;
    // cin >> test_cases;
    while (test_cases--)
        solve();

    return 0;
}
