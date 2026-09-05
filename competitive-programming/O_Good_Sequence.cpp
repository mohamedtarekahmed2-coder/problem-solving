#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n = 1, freq, ans = 0;
    cin >> n;
    vector <int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    sort (nums.begin(), nums.end());
    for (int i = 0; i < n;)
    {
        freq = 1;
        int l = i + 1;
        for (; l < n; l++){
            if (nums[i] == nums[l]) freq++;
            else break;
        }
        if (freq < nums[i]) ans += freq;
        else if (freq > nums[i]) ans += (freq - nums[i]);   
        i = l;
    }
    cout << ans << "\n";
    
    return 0;
}