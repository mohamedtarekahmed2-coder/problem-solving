#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int simulate_removals(vector<queue<int>>& cylid, int num_colors, queue<int>& active_cylid) {
    vector<int> color_location(num_colors + 1, -1);
    int removed_pairs = 0;

    while (!active_cylid.empty()) {
        int current_cylid = active_cylid.front();
        active_cylid.pop();
        if (cylid[current_cylid].empty()) 
            continue;
        
        int top_color = cylid[current_cylid].front();
        if (color_location[top_color] == -1) 
            color_location[top_color] = current_cylid;
        
        else {
            int paired_cylid = color_location[top_color];
            cylid[current_cylid].pop();
            cylid[paired_cylid].pop();
            removed_pairs++;
            active_cylid.push(current_cylid);
            active_cylid.push(paired_cylid);
        }
    }
    return removed_pairs;
}

void solve() {
    int num_colors, num_cylid;
    cin >> num_colors >> num_cylid;

    vector<queue<int>> cylid(num_cylid);
    queue<int> active_cylid;
    for (int i = 0; i < num_cylid; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int color;
            cin >> color;
            cylid[i].push(color);
        }
        active_cylid.push(i);
    }
    print_answer(simulate_removals(cylid, num_colors, active_cylid), num_colors);)
}

void print_answer(int revmoved, int num_colors){
    if (removed == num_colors) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    fast_io();
    solve();

    return 0;
}