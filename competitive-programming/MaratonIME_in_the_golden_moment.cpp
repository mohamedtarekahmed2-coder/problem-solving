#include <iostream>
#include <vector>
using ll = long long;
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<int> read_vector(int size)
{
    vector<int> v(size, 0);
    for (int &element : v)
        cin >> element;

    return v;
}

ll calculate_pairwise_products(const vector<int> &powers)
{
    ll sum = 0, total_power = 0;

    for (int i = (int)powers.size() - 1; i >= 1; i--)
    {
        sum += powers[i];
        total_power += sum * powers[i - 1];
    }
    
    return total_power;
}

int main()
{
    fast_io();

    int num_friends;
    cin >> num_friends;

    vector<int> friends_power = read_vector(num_friends);

    cout << calculate_pairwise_products(friends_power) << '\n';
    return 0;
}