#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define nl cout << '\n'
#define ll long long

void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main() {
    fast_io();
    
    int t = 1;
    cin >> t;
    while (t--) {
        vector <int> arr (7, 1);
        for (int i = 0; i < 7; i++) cin >> arr[i];
        sort(arr.begin(), arr.end());
        for (int i = 5; i >= 0; i--) {
            arr[6] -= arr[i];
        }
        cout << arr[6] << '\n';
    }
    return 0;
}