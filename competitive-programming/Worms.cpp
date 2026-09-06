#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
void Fast_IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<int> ReadVectorAndGetPrefixSum(int size)
{
    vector<int> res(size + 1, 0);
    for (int i = 1; i < res.size(); i++)
    {
        cin >> res[i];
        res[i] += res[i - 1];
    }
    return res;
}

int GetLowerBound(const vector<int> &prefix_sum, int target)
{
    int answer = 0;
    int left = 0, right = prefix_sum.size() - 1;
    while (left <= right)
    {
        int mid = midpoint(left, right);
        if(prefix_sum[mid] >= target)
        {
            answer = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return answer;
}

void Solve()
{
    int piles_num, juicy_worms_num;
    cin >> piles_num;
    vector<int> prefix_sum = ReadVectorAndGetPrefixSum(piles_num);

    cin >> juicy_worms_num;
    int label;
    while (juicy_worms_num--)
    {
        cin >> label;
        cout << GetLowerBound(prefix_sum, label) << '\n';
    }
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