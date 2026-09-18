#include <iostream>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
class LRUCache
{
    struct Node
    {
        Node *prev;
        int key;
        int val;
        Node *next;
        Node(int key = -1, int val = -1)
        {
            this->key = key;
            this->val = val;
            this->prev = nullptr;
            this->next = nullptr;
        }
    };
    int capacity;
    Node *head_dummy;
    Node *tail_dummy;
    unordered_map<int, Node *> key_address;

    void remove(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert(Node *node)
    {
        tail_dummy->prev->next = node;
        node->prev = tail_dummy->prev;
        tail_dummy->prev = node;
        node->next = tail_dummy;
    }

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head_dummy = new Node();
        tail_dummy = new Node();
        head_dummy->next = tail_dummy;
        tail_dummy->prev = head_dummy;
    }

    ~LRUCache()
    {
        tail_dummy = head_dummy;
        while (head_dummy)
        {
            head_dummy = head_dummy->next;
            delete tail_dummy;
            tail_dummy = head_dummy;
        }
    }

    int get(int key)
    {
        if (key_address.contains(key))
        {
            Node *node = key_address[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (key_address.contains(key))
            remove(key_address[key]);

        Node *new_node = new Node(key, value);
        key_address[key] = new_node;
        insert(new_node);

        if (ssize(key_address) > capacity)
        {
            Node *lru = head_dummy->next;
            remove(lru);
            key_address.erase(lru->key);
            delete lru;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
