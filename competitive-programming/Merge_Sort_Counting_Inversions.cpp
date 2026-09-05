#include <iostream>
#include <vector>
using namespace std;

long long merge_sort(vector<int> &v, int lower, int upper)
{

    if (lower >= upper)
        return 0;

    int median = lower + (upper - lower) / 2;
    long long result = merge_sort(v, lower, median) +
                       merge_sort(v, median + 1, upper);

    vector<int> new_v;
    int start = lower, med_start = median + 1;

    while (start <= median && med_start <= upper)
    {
        if (v[start] <= v[med_start])
        {
            new_v.push_back(v[start]);
            start++;
        }
        else
        {
            new_v.push_back(v[med_start]);
            med_start++;
            result += (median - start + 1);
        }
    }

    while (start <= median)
    {
        new_v.push_back(v[start]);
        start++;
    }
    while (med_start <= upper)
    {
        new_v.push_back(v[med_start]);
        med_start++;
    }

    for (int i = 0; i < new_v.size(); i++)
        v[lower + i] = new_v[i];

    return result;
}

int main()
{
    int test_cases;
    cin >> test_cases;
    while (test_cases--)
    {
        int size_v;
        cin >> size_v;
        vector<int> v(size_v);
        for (int i = 0; i < size_v; i++)
            cin >> v[i];

        long long answer = merge_sort(v, 0, size_v - 1);
        cout << answer << '\n';
    }
    return 0;
}