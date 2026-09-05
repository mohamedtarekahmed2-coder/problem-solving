#include <iostream>
#include <set>
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void take_set(set<int> &index_monsters, int num_monsters)
{
    int index;
    for (int i = 0; i < num_monsters; i++)
    {
        cin >> index;
        index_monsters.insert(index);
    }
}

void num_shots(int num_monsters, int distance)
{
    set<int> index_monsters;
    take_set(index_monsters, num_monsters);

    int answer = 0;
    for (auto monster = index_monsters.rbegin(); monster != index_monsters.rend(); monster++)
    {
        if (*monster - answer * distance > 0)
            answer++;
    }
    cout << answer << '\n';
}

int main()
{
    fast_io();

    int test_cases = 1,
        num_monsters, distance;
    cin >> test_cases;
    while (test_cases--)
    {
        cin >> num_monsters >> distance;
        num_shots(num_monsters, distance);
    }

    return 0;
}