#include <iostream>
#include <vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int del = 0;
    //cin >> t;
    string cup;
    cin >> cup;
    vector <char> ans;
    for (int i = cup.size() - 1; i >= 0; i--) {
        if(cup[i] == '<') del++;
        else if (del > 0) del--;
        else ans.push_back(cup[i]);
    }
    for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i];
    cout << "\n";
    return 0;
}