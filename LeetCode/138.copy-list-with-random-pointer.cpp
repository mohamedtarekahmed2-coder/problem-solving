#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
// @lc code=start
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> old_new;
        Node *current = head;
        while (current)
        {
            Node *new_node = new Node(current->val);
            old_new.insert({current, new_node});
            current = current->next;
        }
        current = head;
        while (current)
        {
            old_new[current]->next = old_new[current->next]; 
            old_new[current]->random = old_new[current->random]; 
            current = current->next;
        }
        return old_new[head];
    }
};
// @lc code=end
