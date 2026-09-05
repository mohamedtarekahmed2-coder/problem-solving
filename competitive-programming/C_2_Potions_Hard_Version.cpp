#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main()
{
    fast_io();

    priority_queue<int, vector<int>, greater<int>> neg_potions;
    long long health;
    int num_potions_taken,
        num_potions,
        potion;
    health = num_potions_taken = 0;

    cin >> num_potions;
    while (num_potions--)
    {
        cin >> potion;

        if (potion < 0)
            neg_potions.push(potion);

        health += potion;
        num_potions_taken++;

        if (health < 0)
        {
            health -= neg_potions.top();
            neg_potions.pop();
            num_potions_taken--;
        }
    }
    cout << num_potions_taken << '\n';
    return 0;
}
