#include <iostream>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    short n, a, b;
    ll max = 0, count = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        count += (b - a);
        if (max < count) max = count;
    }
    cout << max << '\n';
    return 0;
}