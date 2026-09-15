#include <iostream>
using namespace std;
/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
    void reorderList(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *prev = nullptr;
        while (slow)
        {
            ListNode *temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        ListNode *start = head, *end = prev;
        while (end->next)
        {
            ListNode *temp = start->next;
            start->next = end;
            start = end;
            end = temp;
        }
        end->next = nullptr;
    }
};
// @lc code=end
