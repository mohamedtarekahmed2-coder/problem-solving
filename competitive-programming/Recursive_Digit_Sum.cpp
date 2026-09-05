#include <iostream>
#include <string>

using namespace std;

long long get_sum(string s) {
    long long total = 0;
    for (char c : s) {
        total += c - '0';
    }
    return total;
}

int super_digit(string p) {
    if (p.size() == 1) return stoi(p); 
    long long current = get_sum(p);
    return super_digit(to_string(current));
}

int main() {
    string n;
    int k;
    cin >> n >> k;
    long long sum = get_sum(n) * k;
    cout << super_digit(to_string(sum)) << endl;

    return 0;
}