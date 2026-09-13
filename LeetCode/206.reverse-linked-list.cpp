#include <iostream>
using namespace std;
/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
    ListNode *reverseList(ListNode *head)
    {
        if(head == nullptr) return head;

        if(head->next == nullptr) return head;

        ListNode *res = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return res;
    }
};
// @lc code=end
