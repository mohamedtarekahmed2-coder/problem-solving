#include <iostream>
#include <math.h>
using namespace std;

int check (string& s, int size){
    int power = (s.size() - 1) - size;
    if (size == -1) return 0;
    else if (s[size] == '7') 
        return (1 << power) + check (s, size - 1);
    else    
        return check (s, size - 1);
}

int main() {
    string num;
    cin >> num;
    int befores = 0;
    befores = (1 << num.size()) - 2;
    cout << befores + check (num, num.size() - 1) + 1 << '\n';
    return 0;
}