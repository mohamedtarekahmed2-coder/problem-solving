#include <iostream>
#include <vector>
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void read_2d_vector(vector<vector<int>> &v, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            cin >> v[i][j];
}

vector<vector<int>> build_prefix_suffix(vector<vector<int>> &v, int columns)
{
    vector<vector<int>> prefix_suffix(2, vector<int>(columns, 0));
    
    int sum = 0;
    for (int i = 0; i < columns - 1; i++)
    {
        sum += v[1][i];
        prefix_suffix[1][i] = sum;
    }

    sum = 0;
    for (int column = columns - 1; column > 0; column--)
    {
        sum += v[0][column];
        prefix_suffix[0][column] = sum;
    }

    return prefix_suffix;
}

int calculate_path (vector<vector<int>> &prefix_suffix, int columns)
{
    int answer = 0;
    int right, down;
    for (int column = 0; column < columns - 1; column++)
    {
        right = prefix_suffix[0][column + 1];
        down = prefix_suffix[1][column];
        if(right > down)
        {
            if(answer < down)
                answer = down;
        }
        else
        {
            if(answer < right)
                answer = right;
            return answer;
        }
    }
    return answer;
}

void solve()
{
    int columns;
    cin >> columns;

    vector<vector<int>> two_rows(2, vector<int>(columns, 0));
    read_2d_vector(two_rows, 2, columns);

    two_rows = build_prefix_suffix(two_rows, columns);

    cout << calculate_path(two_rows, columns) << '\n';
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