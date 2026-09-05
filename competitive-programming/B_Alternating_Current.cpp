#include <iostream>
#include <stack>
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

bool can_simplify(string &current)
{
    int count = static_cast<int>(current.size());
    stack <char> char_st;
    for (int i = 0; i < count; i++)
    {
        if(char_st.empty())
            char_st.push(current.at(i));
        else if (current.at(i) == char_st.top())
            char_st.pop();
        else 
            char_st.push(current.at(i));
    }
    return char_st.empty();
}

int main()
{
    fast_io();
    
    string current;
    cin >> current;
    if (can_simplify(current))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}