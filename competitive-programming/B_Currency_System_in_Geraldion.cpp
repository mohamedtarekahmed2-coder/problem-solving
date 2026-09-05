#include <iostream>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, nums;
    cin >> n;
    bool one = false;
    for (int i = 0; i < n; ++i) {
        cin >> nums;
        if (nums == 1) one = true;
    }
    (one)? cout << -1 << endl : cout << 1 << endl;
    return 0;
}