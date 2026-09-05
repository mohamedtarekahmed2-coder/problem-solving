#include <iostream>
#include <vector>
#include <deque>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int count, num;
    vector<int> builds;
    stack<int> cup;
    deque<int> ans; 

    cin >> count;

    for(int i = 0; i < count; i++)
    {
        cin >> num;
        builds.push_back(num);
    }
    
    for (int i = count - 1; i >= 0; i--)
    {
        ans.push_front(cup.size());
        while (!cup.empty() && cup.top() < builds.at(i)) 
            cup.pop();
        cup.push(builds.at(i));
    }

    for (int i = 0 ; i < count; i++ ) {
        cout << ans.at(i) << ' ';
    }
    
    return 0;
}