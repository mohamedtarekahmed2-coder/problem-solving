#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<ll> read_vector(int count) {
    vector<ll> v(count);
    for (ll &i : v) {
        cin >> i;
    }
    return v;
}

vector<ll> build_prefix_sum(const vector<ll> &v) {
    vector<ll> prefix(v.size() + 1, 0);
    for (int i = 1; i <= v.size(); i++) {
        prefix[i] = prefix[i - 1] + v[i - 1];
    }
    return prefix;
}

void solve() {
    int size;
    cin >> size;
    
    vector<ll> arr = read_vector(size);
    vector<ll> prefix = build_prefix_sum(arr);
    
    ll total_sum = prefix[size]; 
    
    if (total_sum % 3 != 0) {
        cout << 0 << '\n';
        return;
    }
    
    ll target = total_sum / 3;
    int valid_first_parts = 0;
    ll total_ways = 0;
    
    for (int i = 1; i < size; i++) {
        if (prefix[i] == target * 2) {
            total_ways += valid_first_parts;
        }
        if (prefix[i] == target) {
            valid_first_parts++;
        }
    }
    
    cout << total_ways << '\n';
}

int main() {
    fast_io();
    int test_cases = 1;
    // cin >> test_cases;
    while (test_cases--) {
        solve();
    }
    return 0;
}
