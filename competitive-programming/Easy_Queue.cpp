#include <iostream>
#include <queue>

using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void enqueue_op(queue<int>& q) {
    int n;
    cin >> n;
    q.push(n);
}

void dequeue_op(queue<int>& q) {
    if (!q.empty()) 
        q.pop();
}

void print_front_op(queue<int>& q) {
    if (q.empty()) 
        cout << "Empty!\n";
    else 
        cout << q.front() << '\n';
}

void solve() {
    int num_queries;
    cin >> num_queries;
    
    queue<int> q;
    int operation;
    
    while (num_queries--) {
        cin >> operation;
        
        switch (operation) {
            case 1:
                enqueue_op(q);
                break;
            case 2:
                dequeue_op(q);
                break;
            case 3:
                print_front_op(q);
                break;
        }
    }
}

int main() {
    fast_io();
    
    solve();
    
    return 0;
}