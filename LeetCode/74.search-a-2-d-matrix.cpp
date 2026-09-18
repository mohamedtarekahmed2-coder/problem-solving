#include <iostream>
using namespace std;
#include <vector>
#include <numeric>
/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = ssize(matrix), cols = ssize(matrix[0]);
        int left = 0, right = (cols * rows) - 1;
        while (left <= right)
        {
            int mid = midpoint(left, right);
            int row = mid / cols, col = mid % cols;
            int num = matrix[row][col];
            if (num == target)
                return true;
            else if (target < num)
                right = mid - 1;
            else 
                left = mid + 1;
        }
        return false;
    }
};
// @lc code=end

