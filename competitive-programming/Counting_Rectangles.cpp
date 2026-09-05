#include <iostream>
#include <cstring>

using namespace std;
using ll = long long;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

ll Matrix[1001][1001];

void solve()
{
    int count, queries;
    cin >> count >> queries;

    memset(Matrix, 0, sizeof(Matrix));
    int height, width;
    while (count--)
    {
        cin >> height >> width;
        Matrix[height][width] += (ll)height * width;
    }

    for (int i = 1; i <= 1000; i++)
        for (int j = 1; j <= 1000; j++)
            Matrix[i][j] += Matrix[i - 1][j] + Matrix[i][j - 1] - Matrix[i - 1][j - 1];

    int hs, hb, ws, wb;
    ll answer = 0;
    while (queries--)
    {
        cin >> hs >> ws >> hb >> wb;
        hb--;
        wb--;
        answer = Matrix[hb][wb] - Matrix[hs][wb] - Matrix[hb][ws] + Matrix[hs][ws];
        cout << answer << '\n';
    }
}

int main()
{
    fast_io();

    int test_cases = 1;
    cin >> test_cases;
    while (test_cases--)
    {
        solve();
    }

    return 0;
}