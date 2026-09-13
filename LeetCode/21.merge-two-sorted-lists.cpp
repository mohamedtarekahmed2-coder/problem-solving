#include <iostream>
using namespace std;
/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// class Solution
// {
// public:
//     ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
//     {
//         ListNode *dummy = new ListNode();
//         ListNode *tail = dummy;
//         while (list1 != nullptr && list2 != nullptr)
//         {
//             if (list1->val > list2->val)
//             {
//                 tail->next = list2;
//                 list2 = list2->next;
//             }
//             else
//             {
//                 tail->next = list1;
//                 list1 = list1->next;
//             }
//             tail = tail->next;
//         }
//         if (list1 != nullptr)
//         {
//             tail->next = list1;
//         }
//         else if (list2 != nullptr)
//         {
//             tail->next = list2;
//         }
//         ListNode *head = dummy->next;
//         delete dummy;
//         return head;
//     }
// };
// @lc code=start
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if(list1 == nullptr) return list2;
        else if (list2 == nullptr) return list1;
        if(list1->val < list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};
// @lc code=end
