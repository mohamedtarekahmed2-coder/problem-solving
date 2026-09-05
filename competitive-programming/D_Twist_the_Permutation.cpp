#include <iostream>
#include <deque>
#include <vector>
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void read_deque(deque <int> &d){
    for (int i = 0; i < d.size(); i++)
        cin >> d.at(i);
}

void print_vector(vector <int> &v){
    for (int i = 0; i < v.size(); i++)
        cout << v.at(i) << ' ';
    cout << '\n';
}

void solve(deque <int> &nums){
    int size = nums.size();
    vector <int> answer(size, 0);
    for (int i = size - 1; i >= 0; i--)
    {
        int the_largest = i + 1, 
            shifts = 0;
        if (nums.back() == the_largest)
            nums.pop_back();
        else {
            while(nums.back() != the_largest){
                nums.push_back(nums.front());
                nums.pop_front();
                shifts++;
            }
            nums.pop_back();
            answer.at(i) = shifts;
        }
    }
    print_vector(answer);
}

int main() {
    fast_io();
    int test_cases;
    cin >> test_cases;
    while (test_cases--)
    {
        int size;
        cin >> size;
        deque <int> nums(size);
        read_deque(nums);
        solve(nums);
    }

    return 0;
}