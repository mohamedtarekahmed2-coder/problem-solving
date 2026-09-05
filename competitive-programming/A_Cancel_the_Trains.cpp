#include <iostream>
#include <set>
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void num_canceled(int num_trains_bottom, int num_trains_left)
{
    int answer = 0, train;
    set<int> num_trains;

    for (int i = 0; i < num_trains_bottom; i++)
    {
        cin >> train;
        num_trains.insert(train);
    }

    for (int i = 0; i < num_trains_left; i++)
    {
        cin >> train;
        auto canceled = num_trains.insert(train);
        if (!canceled.second) 
            answer++;
    }
    cout << answer << '\n';
}

int main()
{
    fast_io();

    int test_cases = 1, num_trains_bottom, num_trains_left;
    cin >> test_cases;

    while (test_cases--)
    {
        cin >> num_trains_bottom >> num_trains_left;
        num_canceled(num_trains_bottom, num_trains_left);
    }

    return 0;
}