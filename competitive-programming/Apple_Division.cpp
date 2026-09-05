#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


long long tree_apples(int apples_index, const vector <int>& apples, const long long& all_apples, long long apple_g1 = 0){
    if (apples_index < 0)
        return abs(all_apples - (2 * apple_g1));
    return min(tree_apples(apples_index - 1, apples, all_apples, apple_g1 + apples.at(apples_index)), 
               tree_apples(apples_index - 1, apples, all_apples, apple_g1));
}

int main() {
    int num_apples;
    long long all_apples = 0;
    cin >> num_apples;
    vector <int> apples(num_apples,0);
    for (int i = 0; i < num_apples; i++){
        cin >> apples.at(i);
        all_apples += apples.at(i);
    }
    cout << tree_apples(--num_apples, apples, all_apples) << '\n';
    return 0;
}
