#include <iostream>
using namespace std;
int main() {
    int n, k, x;
    cin >> n >> k >> x;
    int a[n]; 
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = 0;
    for (int i = 0; i < n - k; ++i) ans += a[i];
    ans += (k * x);
    cout << ans << endl;
    return 0;
}