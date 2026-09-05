#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
    
//  * make include/exclude algorithm
int min_operations(string &big_s, string &small_s, string test = "", int index = 0, bool stop = false)
{
    if (index == (int)small_s.size() || (stop && (int)test.size() != 0))
    {
        if (big_s.find(test) != string::npos){
            return (int)big_s.size() + (int)small_s.size() - (int)test.size() * 2;
        }else
            return INT_MAX;
    }
    return min(min_operations(big_s, small_s, test + small_s[index], index + 1), min_operations(big_s, small_s, test, index + 1, true));
}

void solve()
{
    //  * take 2 strings
    string big_s, small_s;
    cin >> big_s >> small_s;
    if((int)big_s.size() < (int)small_s.size())
        swap(big_s, small_s);

    cout << min_operations(big_s, small_s) << '\n';
}

int main()
{
    fast_io();

    int test_cases = 1;
    cin >> test_cases;
    while (test_cases--)
        solve();

    return 0;
}