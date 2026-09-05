#include <iostream>
#include <deque>
using namespace std;
#define nl cout << '\n'
#define ll long long

void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main()
{
    fast_io();

    int test_cases, num_opers, oper, numpunct;
    ll ans, total_nums;
    bool rev;
    cin >> test_cases;
    while (test_cases--)
    {
        deque<int> tube;
        total_nums = ans = 0;
        rev = false;
        cin >> num_opers;
        while (num_opers--)
        {
            cin >> oper
    ;
            switch (oper
    )
            {
            case 1:
                if (rev)
                {
                    tube.push_back(tube.front());
                    tube.pop_front();
                    ans += total_nums - tube.size() * tube.back();
                }
                else
                {
                    tube.push_front(tube.back());
                    tube.pop_back();
                    ans += total_nums - tube.size() * tube.front();
                }
                break;
            case 2:
                (rev) ? rev = false : rev = true;
                ans = ((tube.size() + 1) * total_nums) - ans;
                break;
            default:
                cin >> numpunct;
                (rev) ? tube.push_front(numpunct) : tube.push_back(numpunct);
                ans += numpunct * tube.size();
                total_nums += numpunct;
            }
            cout << ans;
            nl;
        }
    }
    return 0;
}