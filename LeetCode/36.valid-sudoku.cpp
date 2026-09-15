#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <map>
using namespace std;
/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_map<int, unordered_set<char>> rows, cols;
        map<pair<int, int>, unordered_set<char>> squares;

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char ch = board[i][j];
                if (ch == '.') continue;
                pair<int, int> square_key = make_pair(i / 3, j / 3);
                if(rows[i].contains(ch) || cols[j].contains(ch) || squares[square_key].contains(ch))
                {
                    return false;
                }
                else 
                {
                    rows[i].insert(ch);
                    cols[j].insert(ch);
                    squares[square_key].insert(ch);
                }
            }
        }
        return true;
    }
};
// @lc code=end
