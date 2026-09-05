#include <iostream>
using namespace std;
int sum_nums(int num_integers){
    int answer = 0;
    cin >> answer;
    if (num_integers == 1) return answer;
    return answer + sum_nums(--num_integers);
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++){
        int num_integers;
        cin >> num_integers;
        cout << "Case " << i << ": " << sum_nums(num_integers) << '\n';
    }
    return 0;
}
