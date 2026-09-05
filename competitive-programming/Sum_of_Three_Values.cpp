#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector <pair<int, int>> read_elements(int size, int target)
{
    int element;
    vector<pair<int, int>> v;
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
    sort(ans.begin(), ans.end());
    for(int i : ans)
        cout << i << ' ';
    cout << '\n';
}

void find_four_sum(vector <pair<int, int>>& elements, int target)
{
    vector<int> ans;
    bool is_possible = false;
    for (int i = 0; i < (int)elements.size(); i++)
    {
        int first = elements[i].first;
        int j = (int)elements.size() - 1;
        for (int l = i + 1; l < j;)
        {
            int second = elements[l].first;
            int third = elements[j].first;
            if ((long long)first + second + third == target)
            {
                ans.push_back(elements[i].second);
                ans.push_back(elements[l].second);
                ans.push_back(elements[j].second);
                is_possible = true;
                break;
            }
            else if ((long long)first + second + third < target)
                l++;
            else
                j--;
        }
        if (is_possible) break;
    }
    if (ans.empty())
        cout << "IMPOSSIBLE\n";
    else
        print(ans);
    
}

void solve()
{
    int element_size, target_num;
    cin >> element_size >> target_num;

    vector <pair<int, int>> elements = read_elements(element_size, target_num);

    find_four_sum(elements, target_num);
}

int main()
{
    fast_io();

    int test_cases = 1;
    // cin >> test_cases;
    while (test_cases--)
    {
        solve();
    }

    return 0;
}