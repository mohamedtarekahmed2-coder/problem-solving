#include <iostream>
#include <stack>
using namespace std;
/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
class MinStack {
    stack<int> mainStack;
    stack<int> minimumStack;
public:
    MinStack() = default;
    
    void push(int value) {
        mainStack.push(value);
        if(minimumStack.empty() || minimumStack.top() >= value)
            minimumStack.push(value);
    }
    
    void pop() {
        if(mainStack.top() == minimumStack.top())
            minimumStack.pop();
        mainStack.pop();
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minimumStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

