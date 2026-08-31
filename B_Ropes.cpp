#include <iostream>
#include <vector>
#include <iomanip> 
using namespace std;
using ll = long long;
using ld = long double;

void Fast_IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<ld> ReadVector(int size)
{
    vector<ld> v(size);
    for(ld &i : v)
        cin >> i;
    return v;
}

bool can(ld mid, const vector<ld> &v, int pieces)
{
    ll sum_pieces = 0;
    for (int i = 0; i < v.size(); i++)
        sum_pieces += (ll)(v[i] / mid);
    return sum_pieces >= pieces;
}

void Solve()
{
    int size, pieces; 
    cin >> size >> pieces;
    vector<ld> v = ReadVector(size);

    ld left = 0, right = 1e7, answer = 0; 
    int iterations = 150; 
    while (iterations--)
    {
        ld mid = left + (right - left) / 2.0;
        if(can(mid, v, pieces))
        {
            answer = mid;
            left = mid;
        }
        else
        {
            right = mid;
        }
    }
    cout << fixed << setprecision(6) << answer << '\n';
}

int main()
{
    Fast_IO();

    int test_cases = 1;
    // cin >> test_cases;
    while (test_cases--)
    {
        Solve();
    }
    return 0;
}