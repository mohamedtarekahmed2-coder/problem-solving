#include <iostream>
#include <stack>
#include <string>
using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

bool is_matching_pair(char open, char close) {
    if (open == '(' && close == ')') return true;
    if (open == '{' && close == '}') return true;
    if (open == '[' && close == ']') return true;
    return false;
}

string is_balanced(string &s) {
    stack<char> st;

    for (char bracket : s) {
        if (bracket == '(' 
            || bracket == '{' 
            || bracket == '[')
            st.push(bracket);
        else {
            if (st.empty()) 
                return "NO";
            char top_bracket = st.top();
            if (is_matching_pair(top_bracket, bracket)) 
                st.pop(); 
            else 
                return "NO"; 
        }
    }
    if (st.empty()) 
        return "YES";
    else 
        return "NO";
}

void solve() {
    int num_strings;
    cin >> num_strings;
    
    while (num_strings--) {
        string s;
        cin >> s;
        cout << is_balanced(s) << '\n';
    }
}

int main() {
    fast_io();
    solve();

    return 0;
}