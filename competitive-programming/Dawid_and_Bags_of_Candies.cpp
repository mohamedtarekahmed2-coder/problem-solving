#include <iostream>
#include <vector>
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

bool solve(const vector<int> &bags, int first_f = 0, int second_f = 0, int time = 0)
{
    if (time == 4)
    {
        if (first_f == second_f)
            return true;
        else
            return false;
    }
    return solve(bags, first_f + bags[time], second_f, time + 1) || solve(bags, first_f, second_f + bags[time], time + 1);
}

void read_vector(vector<int> &v, int size)
{
    for (int i = 0; i < size; i++)
        cin >> v[i];
}

int main()
{
    fast_io();
    vector<int> bags(4, 0);
    read_vector(bags, 4);
    if (solve(bags))
        cout << "YES";
    else
        cout << "NO";
    cout << "\n";

    return 0;
}