#include <iostream>
#include <math.h>
using namespace std;

bool canAchieve(const int& gold_nuggets, int target){
    if (gold_nuggets < target ) return false;
    else if (gold_nuggets == target) return true;
    else {
        if (fmod((target * 1.5), 1.0) != 0.0) 
            return canAchieve (gold_nuggets, target * 3);
        else
            return canAchieve (gold_nuggets, target * 3) || canAchieve (gold_nuggets, target * 1.5);
    }
}

int main() {
    short test_cases;
    cin >> test_cases;
    int gold_nuggets, target;
    while (test_cases--)
    {
        cin >> gold_nuggets >> target;
        (canAchieve (gold_nuggets, target))? cout << "YES\n": cout << "NO\n";
    }
    return 0;
}
