#include <iostream>
using namespace std;

void remove_num(const int& length, const int& to_remove, int& index){
    if (index == length) return;
    int num;
    cin >> num;
    if (num != to_remove) cout << num << ' ';
    remove_num(length, to_remove, ++index);
}

int main() {
    int length, removed_num, index = 0;
    cin >> length >> removed_num;
    remove_num(length, removed_num, index);
    cout << '\n';
    return 0;
}

// fast_io();
// int t = 1;
// //cin >> t;
// while (t--) solve();
// #define ll long long
// void fast_io()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
// }