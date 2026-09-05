#include <iostream>
#include <vector>
using namespace std;

void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int MAX = 200005;
int diff_arr[MAX] = {};

void solve()
{
    int num_recipes, min_recipes, num_questions;
    cin >> num_recipes >> min_recipes >> num_questions;

    int start, end;
    for (int i = 0; i < num_recipes; i++)
    {
        cin >> start >> end;
        diff_arr[start]++;
        diff_arr[end + 1]--;
    }

    int sum = 0;
    for (int i = 0; i < MAX; i++)
    {
        sum += diff_arr[i];
        diff_arr[i] = sum;
    }

    sum = 0;
    for (int i = 0; i < MAX; i++)
    {
        if (diff_arr[i] >= min_recipes)
            sum++;
        diff_arr[i] = sum;
    }

    while (num_questions--)
    {
        cin >> start >> end;
        cout << diff_arr[end] - diff_arr[start - 1] << '\n';
    }
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