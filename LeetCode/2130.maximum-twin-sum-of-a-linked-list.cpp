#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
 * @lc app=leetcode id=2130 lang=cpp
 *
 * [2130] Maximum Twin Sum of a Linked List
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
class Solution
{
public:
    int pairSum(ListNode *head)
    {
        ListNode *prev = nullptr, *slow = head, *fast = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            ListNode *temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        int max_twin = 0;
        while (prev)
        {
            max_twin = max(max_twin, prev->val + slow->val);
            prev = prev->next;
            slow = slow->next;
        }
        return max_twin;
    }
};
// @lc code=end
