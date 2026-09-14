#include <iostream>
using namespace std;
/*
 * @lc app=leetcode id=1472 lang=cpp
 *
 * [1472] Design Browser History
 */

// @lc code=start
class BrowserHistory {
    struct Node
    {
        Node *prev;
        string url;
        Node *next;
        Node (Node *back = nullptr, string url = "", Node *forward = nullptr)
        {
            this->prev = back;
            this->url = url;
            this->next = forward;            
        }
    };
    Node *head;
    Node *current;

    void delete_forward()
    {
        Node *del = current->next;
        Node *ref = del;
        while (del)
        {
            ref = ref->next;
            delete del;
            del = ref;
        }
    }
public:
    BrowserHistory(string homepage) {
        head = new Node(nullptr, homepage);
        current = head;
    }

    ~BrowserHistory() {
        current = head;
        while (head)
        {
            current = current->next;
            delete head;
            head = current;
        }
    }
    
    void visit(string url) {
        delete_forward();
        Node *new_node = new Node(current, url);
        current->next = new_node;
        current = current->next;
    }
    
    string back(int steps) {
        for (int i = 0; current->prev && i < steps; i++)
            current = current->prev;
        return current->url;
    }
    
    string forward(int steps) {
        for (int i = 0; current->next && i < steps; i++)
            current = current->next;
        return current->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
// @lc code=end

