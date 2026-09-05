#include <iostream>

using namespace std;

int min_not_zero(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    return (a < b) ? a : b;
}

int tree(int num, const int &goal, int index)
{
    if (num == goal)
        return index;
    if (num > goal)
        return 0;
    return min_not_zero(tree(num * 2, goal, index + 1), tree(num * 3, goal, index + 1));
}
int main()
{
    int num, goal;
    cin >> num >> goal;
    if (num == goal)
    {
        cout << "0\n";
        return 0;
    }
    int n = tree(num, goal, 0);
    if (n)
        cout << n;
    else
        cout << "-1\n";
    return 0;
}