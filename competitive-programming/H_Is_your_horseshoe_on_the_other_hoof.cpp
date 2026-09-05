#include <iostream>
#include <algorithm>
using namespace std;

void solve (int arr[4]){
    int ans = 0;
    sort(arr, arr + 4);
        for (short i = 0; i < 3; i++){
            if (arr[i] == arr[i + 1]) {
                ans++;
            }
        }
        cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1, ans = 0;
    //cin >> t;
    while (t--) {
        int arr[4];
        for (short i = 0; i < 4; i++) cin >> arr[i];
        solve(arr);
    }
    return 0;
}