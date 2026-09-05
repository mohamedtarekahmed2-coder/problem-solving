#include <iostream>
#include <deque>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    //cin >> t;

    string s;
    cin >> s;
    deque <char> test (s.size());
    bool ans = true;
    for (char& i : test) cin >> i;
    while (t--) {
        for (short i = 0; i < s.size(); i++)
        {
            ans = true;
            for (short l = 0; l < s.size(); l++)
            {
                if (s[l] != test[l]) ans = false;
                if (!ans) break;
            }
            if (ans) break;
            test.push_front(test.back());
            test.pop_back();
        }
        (ans)? cout << "Yes\n" : cout << "No\n";
    }
    return 0;
}