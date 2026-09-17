#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, q;
    cin >> n >> k >> q;

    vector<vector<int>> b(k, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int val;
            cin >> val;
            if (i == 0)
                b[j][i] = val;
            else
                b[j][i] = b[j][i - 1] | val;
        }
    }

    while (q--)
    {
        int m;
        cin >> m;

        int min_country = 1;
        int max_country = n;

        while (m--)
        {
            int r, c;
            char op;
            cin >> r >> op >> c;
            r--;
            if (op == '>')
            {
                int pos = upper_bound(b[r].begin(), b[r].end(), c) - b[r].begin();
                min_country = max(min_country, pos + 1);
            }
            else
            {
                int pos = lower_bound(b[r].begin(), b[r].end(), c) - b[r].begin();
                max_country = min(max_country, pos);
            }
        }
        if (min_country <= max_country)
            cout << min_country << "\n";
        else
            cout << -1 << "\n";
    }

    return 0;
}