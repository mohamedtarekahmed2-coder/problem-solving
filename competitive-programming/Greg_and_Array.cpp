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

struct Operation {
    int l, r;
    ll d;
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<ll> a = read_vector(n);

    vector<Operation> ops(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> ops[i].l >> ops[i].r >> ops[i].d;
    }
    
    vector<ll> ops_diff(m + 2, 0);
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        ops_diff[x]++;
        ops_diff[y + 1]--;
    }

    vector<ll> op_count(m + 2, 0);
    for (int i = 1; i <= m; i++) {
        op_count[i] = op_count[i - 1] + ops_diff[i];
    }

    vector<ll> arr_diff(n + 2, 0);
    for (int i = 1; i <= m; i++) {
        ll total_add = op_count[i] * ops[i].d;
        arr_diff[ops[i].l] += total_add;
        arr_diff[ops[i].r + 1] -= total_add;
    }

    ll current_add = 0;
    for (int i = 1; i <= n; i++) {
        current_add += arr_diff[i];
        cout << a[i - 1] + current_add << " "; 
    }
    cout << '\n';
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