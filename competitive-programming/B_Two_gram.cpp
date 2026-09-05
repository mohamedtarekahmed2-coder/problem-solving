#include <iostream>
#include <map>
#include <string>
using namespace std;
void fast_io();

void solve(){
    short size_str, big_freq = 0;
    string str, answer, test;
    map < string, int > m;
    cin >> size_str >> str;
    for (int i = 0; i + 1 < size_str; ++i){
        test = ""s + str[i] + str[i+1];
        m[test]++;
        if (m[test] > big_freq){
            big_freq = m[test];
            answer = test;
        }
    }
    cout << answer << '\n';
}
int main() {
    fast_io();
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}

void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}