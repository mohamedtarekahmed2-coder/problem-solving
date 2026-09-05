#include <iostream>
#include <algorithm>
using namespace std;

short solve (short& n, int arr[], short& m){
    sort(arr, arr + m);
    short ans = 1000;
    for (short i = 0; ans && i < m - n + 1; i++)
        if (arr[i + n - 1] - arr[i] < ans) ans = arr[i + n - 1] - arr[i];
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    short num_students, num_types;
    cin >> num_students >> num_types;
    int types[num_types];
    for (short i = 0; i < num_types; i++) cin >> types[i];
    cout << solve(num_students, types, num_types) << '\n';
    return 0;
}