#include <iostream>
using namespace std;
int num_trucks(int num_crates, const int &load_size){
    if (num_crates <= load_size)return 1;
    else if (num_crates & 1){
        return num_trucks(num_crates / 2, load_size) + num_trucks( ( num_crates + 1 ) / 2, load_size );
    }
    else return 2 * num_trucks(num_crates / 2, load_size);
}
int main() {
    int num_crates, load_size;
    while(cin >> num_crates >> load_size)
        cout << num_trucks(num_crates, load_size) << '\n';
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