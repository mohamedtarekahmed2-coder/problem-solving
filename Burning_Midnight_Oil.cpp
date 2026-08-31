#include <iostream>
using namespace std;
void Fast_IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

bool can(int mid, int grow, int target)
{
    int sum = 0;
    while (mid)
    {
        sum += mid;
        mid /= grow;
    }
    return sum >= target;
}

int Answer(int lines, int productivity)
{
    int left = 1, right = lines, answer = lines;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (can(mid, productivity, lines))
        {
            answer = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return answer;
}

void Solve()
{
    int lines, productivity;
    cin >> lines >> productivity;

    cout << Answer(lines, productivity) << '\n';
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