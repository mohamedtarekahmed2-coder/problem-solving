#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, a = 1, b = 1, index;
    cin >> n;
    
    short arrP[n], arrQ[n], sorted[n];
    for (short i = 0; i < n; i++) cin >> arrP[i];
    for (short i = 0; i < n; i++){
        cin >> arrQ[i];
        sorted[i] = arrQ[i];
    }
    sort(sorted, sorted + n);
    int loc = 1;
    do {
        loc++;
        index = n;
        for (short i = 0; i < n; i++)
        {
            if (sorted[i] == arrQ[i]){
                index--;
                if (index == 0)a = loc;
            }
            else break;
        }
        index = n;
        for (short i = 0; i < n; i++)
        {
            if (sorted[i] == arrP[i]){
                index--;
                if (index == 0)b = loc;
            }
            else break;
        }
    } while (next_permutation(sorted, sorted + n));
    cout << abs(a-b) << '\n';
    return 0;
}