#include <iostream>
#include <deque>
#include <string>

using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve(int num_queries) {
    deque<int> jobs;
    bool is_reversed = false;
    string command;
    int element;

    for (int i = 0; i < num_queries; i++) {
        cin >> command;

        if (command == "reverse") 
            is_reversed = !is_reversed;

        else if (command == "front") {
            if (jobs.empty()) 
                cout << "No job for Ada?\n";
            else {
                if (is_reversed) {
                    cout << jobs.back() << '\n';
                    jobs.pop_back();
                } 
                else {
                    cout << jobs.front() << '\n';
                    jobs.pop_front();
                }
            }
        } 

        else if (command == "back") {
            if (jobs.empty()) 
                cout << "No job for Ada?\n";
            else {
                if (is_reversed) {
                    cout << jobs.front() << '\n';
                    jobs.pop_front();
                } 
                else {
                    cout << jobs.back() << '\n';
                    jobs.pop_back();
                }
            }
        } 

        else if (command == "push_back") {
            cin >> element;
            if (is_reversed) 
                jobs.push_front(element);
            else 
                jobs.push_back(element);
        } 
        
        else if (command == "toFront") {
            cin >> element;
            if (is_reversed) 
                jobs.push_back(element);
            else 
                jobs.push_front(element);
        }
    }
}

int main() {
    fast_io();
    
    int num_queries;
    cin >> num_queries;
    solve(num_queries);
    
    return 0;
}