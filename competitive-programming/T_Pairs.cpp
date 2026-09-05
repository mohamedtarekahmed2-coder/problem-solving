#include <iostream>
#include <vector>
using namespace std;
#define nl cout << '\n'
#define ll long long

int num1, num2;
bool Test_x_and_y (vector <pair<int, int>>& pairs, int x, int y1, int y2){
    pair <int, int> num1 = {x, y1};
    pair <int, int> num2 = {x, y2};
    bool no1 = true, no2 = true;
    int size = pairs.size(); 
    // pair 1
    for (int i = 1; i < size; i++)
    {
        if (num1.first != pairs.at(i).first && 
        num1.second != pairs.at(i).first && 
        num1.first != pairs.at(i).second && 
        num1.second != pairs.at(i).second){
            no1 = false;
            break;
        }
    }
    // pair 2
    for (int i = 1; i < size; i++)
    {
        if (num2.first != pairs.at(i).first && 
        num2.second != pairs.at(i).first && 
        num2.first != pairs.at(i).second && 
        num2.second != pairs.at(i).second){
            no2 = false;
            break;
        }
    }
    return no1 || no2;
}

bool Test_x (vector <pair<int, int>>& pairs){
    pair <int, int> num = {pairs.at(0).first, pairs.at(0).second};
    int size = pairs.size(); 
    bool no1 = true, no2 = true;
    for (int i = 1; i < size; i++)
    {
        if (num.first != pairs.at(i).first && 
        num.first != pairs.at(i).second){
            no1 = Test_x_and_y (pairs, num.first, pairs.at(i).first, pairs.at(i).second);
            break;
        }
    }
    for (int i = 1; i < size; i++)
    {
        if (num.second != pairs.at(i).first && 
        num.second != pairs.at(i).second){
            no2 = Test_x_and_y (pairs, num.second, pairs.at(i).first, pairs.at(i).second);
            break;
        }
    }
    return no1 || no2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, count;
    vector <pair<int, int>> pairs;
    cin >> n >> count;
    for (int i = 0; i < count; i++){
        cin >> num1 >> num2;
        pairs.push_back({num1, num2});
    }
    (Test_x (pairs))? cout << "YES\n" : cout << "NO\n";
    return 0;
}