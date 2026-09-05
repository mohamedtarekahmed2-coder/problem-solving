#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, a, b, ans = 0;
    long long size = 0;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        size += a;
        arr[i] = a - b;
    }
    sort(arr, arr + n, greater<>());
    for (int i = 0; (size > m) && (i < n); i++)
    {
        ans++;
        size -= arr[i];
    }
    (size <= m)? cout << ans : cout << "-1";
    cout << '\n';
    return 0;
}