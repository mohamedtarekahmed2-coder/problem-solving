#include <iostream>
using namespace std;
/*
 * @lc app=leetcode id=707 lang=cpp
 *
 * [707] Design Linked List
 */

// @lc code=start
class MyLinkedList
{
    struct Node
    {
        int val;
        Node *next;
        Node *prev;
        Node(int val = 0)
        {
            this->val = val;
            prev = next = nullptr;
        }
    };

    Node *head, *tail;
    int size;

public:
    MyLinkedList()
    {
        head = tail = nullptr;
        size = 0;
    }
    ~MyLinkedList()
    {
        Node *current;
        while (head != nullptr)
        {
            current = head->next;
            delete head;
            head = current;
        }
    }

    int get(int index)
    {
        if (index < 0 || size <= index)
            return -1;
        else if (index == 0)
        {
            return head->val;
        }
        else
        {
            Node *current = head;
            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }
            return current->val;
        }
    }

    void addAtHead(int val)
    {
        Node *new_node = new Node(val);
        if (size == 0)
        {
            head = tail = new_node;
        }
        else
        {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
        size++;
    }

    void addAtTail(int val)
    {
        Node *new_node = new Node(val);
        if (size == 0)
        {
            head = tail = new_node;
        }
        else
        {
            new_node->prev = tail;
            tail->next = new_node;
            tail = new_node;
        }
        size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index < 0 || size < index)
            return;
        else if (index == 0)
        {
            addAtHead(val);
            return;
        }
        else if (index == size)
        {
            addAtTail(val);
            return;
        }
        else
        {
            Node *current = head;
            Node *new_node = new Node(val);
            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }
            new_node->next = current;
            new_node->prev = current->prev;
            current->prev = new_node;
            new_node->prev->next = new_node;
            size++;
        }
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || size <= index || size == 0)
            return;
        else if (size == 1)
        {
            delete head;
            head = tail = nullptr;
        }
        else if (index == 0)
        {
            head = head->next;
            delete head->prev;
            head->prev = nullptr;
        }
        else if (index == size - 1)
        {
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        }
        else
        {
            Node *current = head;
            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
        }
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
