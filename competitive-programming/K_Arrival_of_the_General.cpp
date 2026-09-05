#include <iostream>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    int a[n];
    int maxv = 0, minv = 101;
    int maxi = 0, mini = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] > maxv) {
            maxv = a[i];
            maxi = i;
        }
        if (a[i] <= minv) {
            minv = a[i];
            mini = i;
        }
    }
    int ans = maxi + (n - 1 - mini);
    if (maxi > mini) ans--;
    cout << ans << endl;
    return 0;
}