#include <iostream>

using namespace std;

bool even_upper_letter(string &str, int index);

bool odd_lower_letter(string &str, int index = 0){
    bool result = true;
    if (isupper(str[index])) result = false;
    if (index == str.size() - 1) return result;
    else return result && even_upper_letter(str, ++index);
}
bool even_upper_letter(string &str, int index){
    bool result = true;
    if (islower(str[index])) result = false;
    if (index == str.size() - 1) return result;
    else return result && odd_lower_letter(str, ++index);
}

int main() {
    string str;
    cin >> str;
    (odd_lower_letter(str))? cout << "Yes\n" : cout << "No\n";
    return 0;
}

// fast_io();
// int t = 1;
// //cin >> t;
// while (t--) solve();
// #define nl cout << '\n'
// #define ll long long
// void fast_io()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
// }