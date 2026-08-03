#include <iostream>
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve()
{
    int num_houses, num_colors;
    cin >> num_houses >> num_colors;

    int max_length = 1, current_length = 1;
    int color1, color2;
    cin >> color1;
    for (int i = 1; i < num_houses; i++)
    {
        cin >> color2;
        if (color2 == color1) current_length = 1;
        else current_length++;
        max_length = max(max_length, current_length);
        color1 = color2;
    }

    cout << max_length << '\n';
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