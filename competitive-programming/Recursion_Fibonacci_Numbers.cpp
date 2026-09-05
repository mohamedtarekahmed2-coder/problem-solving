#include <iostream>

using namespace std;

int fibonacci(int number){
    if (number <= 1) return number;
    else return fibonacci( number - 1 ) + fibonacci( number - 2);
}

int main() {
    short number;
    cin >> number;
    cout << fibonacci(number) << '\n';
    return 0;
}
