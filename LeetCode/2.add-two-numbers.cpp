#include <iostream>
using namespace std;
/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = l1, *prev = nullptr;
        int carry = 0;
        while (l1 && l2)
        {
            carry += l1->val + l2->val;
            l1->val = carry % 10;
            carry /= 10;
            prev = l1;
            l1 = l1->next;
            ListNode *del = l2;
            l2 = l2->next;
            delete del;
        }
        while (l1)
        {
            carry += l1->val;
            l1->val = carry % 10;
            carry /= 10;
            prev = l1;
            l1 = l1->next;
        }
        while (l2)
        {
            prev->next = l2;
            carry += l2->val;
            l2->val = carry % 10;
            carry /= 10;
            prev = l2;
            l2 = l2->next;
        }
        if (carry)
        {
            ListNode *new_node = new ListNode(carry);
            prev->next = new_node;
        }
        return head;
    }
};
// @lc code=end
