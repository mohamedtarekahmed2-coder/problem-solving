#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<int> read_vector(int size)
{
    vector<int> v(size);
    for (int &i : v)
        cin >> i;
    return v;
}

void solve()
{
    int ingredients_n, magic_powder_g;
    cin >> ingredients_n >> magic_powder_g;
    vector<int> grams_needed = read_vector(ingredients_n);
    vector<int> grams_has = read_vector(ingredients_n);

    int left = 0, right = 2002, answer = 0;
    while (left <= right)
    {
        int mid = midpoint(left, right);
        int count = 0, cal = 0;
        for (int i = 0; i < ingredients_n; i++)
        {
            cal = (grams_needed[i] * mid) - grams_has[i];
            if (cal > 0)
                count += cal;
        }

        if(count <= magic_powder_g)
        {
            answer = mid;
            left = mid + 1;
        }
        else 
            right = mid - 1;
    }
    cout << answer << '\n';
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