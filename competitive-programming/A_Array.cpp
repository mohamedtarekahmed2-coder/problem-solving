#include <iostream>
#include <vector>
using namespace std;

void it_is_empty(vector<int> &v_test, vector<int> &v_1)
{
    v_test.push_back(v_1.at(v_1.size() - 1));
    v_1.pop_back();
    v_test.push_back(v_1.at(v_1.size() - 1));
    v_1.pop_back();
}

void print(vector<int> &v)
{
    cout << v.size() << ' ';
    for (int i = 0; i < v.size(); i++)
        cout << v.at(i) << ' ';
    cout << '\n';
}

int main()
{
    int size_array, number;
    cin >> size_array;
    vector<int> pos, neg, zero;

    for (int i = 0; i < size_array; i++)
    {
        cin >> number;
        if (number > 0)
            pos.push_back(number);
        else if (number < 0)
            neg.push_back(number);
        else
            zero.push_back(number);
    }
    if (pos.size() == 0)
        it_is_empty(pos, neg);
    if (!(neg.size() & 1))
    {
        zero.push_back(neg.at(neg.size() - 1));
        neg.pop_back();
    }
    print(neg);
    print(pos);
    print(zero);
    return 0;
}
