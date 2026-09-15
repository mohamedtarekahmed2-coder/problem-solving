#include <iostream>
using namespace std;
/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *slow = dummy, *fast = head;
        int loop = n;
        while (loop--)
        {
            fast = fast->next;
        }
        while (fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *del = slow->next;
        slow->next = slow->next->next;
        head = dummy->next;
        delete del;
        delete dummy;
        return head;
    }
};
// @lc code=end
