#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
//  * read vector of plack( num_planks + 1)
void read_vector(vector<int> &v, int start = 0)
{
    for (int i = start; i < (int)v.size(); i++)
        cin >> v.at(i);
}

//  * make pre_sum v_plack
void make_pre_sum(vector<int> &pre, vector<int> &v)
{
    for (int i = 1; i < (int)pre.size(); i++)
        pre.at(i) = pre.at(i - 1) + v.at(i);
}

//  * loop to get min(pre_sum[i - 1] - pre_sum[i + width_piano - 1], min) i += width_piano
int get_min(vector<int> &pre, int width_piano)
{
    int min_val = INT_MAX;
    int index_min = 0, val;
    for (int i = 1; (i + width_piano - 1) < (int)pre.size(); i++)
    {
        val = pre.at(i + width_piano - 1) - pre.at(i - 1);
        if (min_val > val)
        {
            min_val = val;
            index_min = i;
        }
    }
    return index_min;
}

int main()
{
    fast_io();

    // * take num_planks & width_piano
    int num_planks, width_piano;
    cin >> num_planks >> width_piano;

    vector<int> plank_heights(num_planks + 1, 0);
    read_vector(plank_heights, 1);

    vector<int> pre_sum(num_planks + 1, 0);
    make_pre_sum(pre_sum, plank_heights);

    cout << get_min(pre_sum, width_piano) << '\n';
    return 0;
}