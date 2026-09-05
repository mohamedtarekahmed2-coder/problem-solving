#include <iostream>
#include <deque>
using namespace std;
#define nl cout << '\n'
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, card, point, Sereja_score = 0, Dima_score = 0;
    cin >> n;
    deque <int> cards;
    for(int i = 0; i < n; i++){
        cin >> card;
        cards.push_back(card);
    }
    for(int i = 0; i < n; i++){
        if (cards.front() > cards.back()) {
            point = cards.front();
            cards.pop_front();
        }else{
            point = cards.back();
            cards.pop_back();
        }
        if (i % 2 == 0) Sereja_score += point;
        else Dima_score += point;
    }
    cout << Sereja_score << ' ' << Dima_score;
    nl;
    return 0;
}