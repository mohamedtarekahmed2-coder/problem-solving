#include <iostream>
#include <vector>
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void read_vector(vector <int> &v, int count){
    for (int i = 1; i < count; i++)
        cin >> v.at(i);
}

void print_vector (const vector <int> &v, int start, int end){
    for (int i = start; i < end; i++)
        cout << v.at(i) << ' ';
}

void solve(const vector <int> &v, const vector <int> &old_ordered, int size_arr){
    int taken = size_arr;
    for (int i = size_arr - 1; i > 0; i--)
    {
        if (old_ordered[i] < taken){
            print_vector(v, old_ordered[i], taken);
            taken = old_ordered[i];
        }
    }
    cout << '\n';
}



int main() {
    fast_io();
    int test_cases;
    cin >> test_cases;
    while (test_cases--)
    {
        int size;
        cin >> size;
        size++;
        vector <int> original_cards (size, 0);
        vector <int> old_ordered (size, 0);
        read_vector(original_cards, size);
        for (int i = size - 1; i > 0; i--)
            old_ordered[original_cards[i]] = i;
        solve(original_cards, old_ordered, size);
    }
    return 0;
}