#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_teams(vector<int> &skill_1, vector<int> &skill_2, vector<int> &skill_3)
{
    int teams = min(skill_1.size(), min(skill_2.size(), skill_3.size()));
    cout << teams << '\n';
    while (teams--)
    {
        cout << skill_1.back() << ' ' << skill_2.back() << ' ' << skill_3.back() << '\n';
        skill_1.pop_back();
        skill_2.pop_back();
        skill_3.pop_back();
    }
}
void read_children(vector<int> &skill_1, vector<int> &skill_2, vector<int> &skill_3)
{
    int num_children, skill;
    cin >> num_children;
    for (int i = 1; i <= num_children; i++)
    {
        cin >> skill;
        switch (skill)
        {
        case 1:
            skill_1.push_back(i);
            break;
        case 2:
            skill_2.push_back(i);
            break;
        case 3:
            skill_3.push_back(i);
            break;
        }
    }
}
int main()
{
    vector<int> skill_1, skill_2, skill_3;
    read_children(skill_1, skill_2, skill_3);
    print_teams(skill_1, skill_2, skill_3);

    return 0;
}
