#include <iostream>
#include <string>
#include <cctype>
using namespace std;
/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution
{
public:
    bool isPalindrome(string input_text)
    {
        int left = 0, right = (int)input_text.size() - 1;
        while (left <= right)
        {
            while (left <= right && !isalnum(input_text[left]))
                left++;
            while (left <= right && !isalnum(input_text[right]))
                right--;
            if (left <= right && tolower(input_text[left++]) != tolower(input_text[right--]))
                return false;
        }
        return true;
    }
};
// @lc code=end
