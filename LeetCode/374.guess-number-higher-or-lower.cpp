#include <iostream>
using namespace std;
#include <numeric>
/*
 * @lc app=leetcode id=374 lang=cpp
 *
 * [374] Guess Number Higher or Lower
 */
int guess(int num)
{
    return 0;
}
// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n, res;
        while (left <= right)
        {
            int mid = midpoint(left, right);
            res = guess(mid);
            if (res == 0)
                return mid;
            else if (res == 1)
                left = mid + 1;
            else 
                right = mid - 1;
        }
        return 0;
    }
};
// @lc code=end

