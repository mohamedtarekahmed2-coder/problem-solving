#include <iostream>
using namespace std;
#define ll long long

int main() {
    int n;
    ll total_arr = 0, ans = 0, x;
    cin >> n;
    ll arr[n];
    for (int i = 0; i < n; i++) 
    {
        cin >> x;
        arr[i] = x;
        total_arr += x;
    }
    cin >> x;
    ans += (x / total_arr) * n;
    x %= total_arr;
    for (int i = 0; i < n; i++)
    {
        x -= arr[i];
        ans ++;
        if ( x < 0 )break;
    }
    cout << ans << '\n';
    return 0;
}