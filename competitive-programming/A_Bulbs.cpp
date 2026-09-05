#include <iostream>
#include <set>
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

bool all_bulbs_on(int num_buttons, int num_bulbs){
    set<int> bulbs_on;
    int num_turned_on, bulbs_per_button;

    for (int i = 0; i < num_buttons; i++)
    {
        cin >> bulbs_per_button;

        for (int t = 0; t < bulbs_per_button; t++)
        {
            cin >> num_turned_on;
            bulbs_on.insert(num_turned_on);
        }
    }
    
    return bulbs_on.size() == num_bulbs ;
}

int main()
{
    fast_io();

    int num_buttons, num_bulbs;
    cin >> num_buttons >> num_bulbs;
    cout << (all_bulbs_on(num_buttons, num_bulbs)? "YES" : "NO") << '\n';

    return 0;
}