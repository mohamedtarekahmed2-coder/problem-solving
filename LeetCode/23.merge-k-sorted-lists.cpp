#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *dummy = new ListNode();
        ListNode *tail = dummy;
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val > list2->val)
            {
                tail->next = list2;
                list2 = list2->next;
            }
            else
            {
                tail->next = list1;
                list1 = list1->next;
            }
            tail = tail->next;
        }
        if (list1 != nullptr)
            tail->next = list1;
        else if (list2 != nullptr)
            tail->next = list2;
        ListNode *head = dummy->next;
        delete dummy;
        return head;
    }

    ListNode *divide(vector<ListNode *> &lists, int l, int r)
    {
        if (l == r)
            return lists[l];
        else if (l > r)
            return nullptr;
        int mid = midpoint(l, r);
        ListNode* left = divide(lists, l, mid);
        ListNode* right = divide(lists, mid + 1, r);
        return mergeTwoLists(left, right);
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return nullptr;
        return divide(lists, 0, ssize(lists) - 1);
    }
};
// @lc code=end
