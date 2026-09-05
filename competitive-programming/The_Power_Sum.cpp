#include <iostream>
#include <cmath> 

int power_sum(const int &target, const int &power, int root, int sum){
    if (sum == target)
        return 1;
    else if (sum > target || std::pow(root, power) > target) 
        return 0;
    else return power_sum(target, power, root + 1, sum + std::pow(root, power)) +
                power_sum(target, power, root + 1, sum);
}

int main() {
    int target, power;
    std::cin >> target >> power;
    int answer = power_sum(target, power, 1, 0);
    std::cout << answer << '\n';
    return 0;
}
