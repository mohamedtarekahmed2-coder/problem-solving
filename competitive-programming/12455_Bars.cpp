#include <iostream>
#include <vector>
using namespace std;

bool check(const int &target, int num_bars, const vector<int> &bars, int subbars = 0)
{
    if (subbars > target)
        return false;
    else if (subbars == target)
        return true;
    else if (num_bars == -1)
        return false;
    else
        return check(target, num_bars - 1, bars, subbars + bars.at(num_bars)) ||
               check(target, num_bars - 1, bars, subbars);
}

int main()
{
    short test_cases;
    cin >> test_cases;
    while (test_cases--)
    {
        int target, num_bars;
        cin >> target >> num_bars;
        vector<int> bars(num_bars, 0);
        for (int i = 0; i < num_bars; i++)
            cin >> bars.at(i);
        bool answer = check(target, num_bars - 1, bars);
        (answer) ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}
