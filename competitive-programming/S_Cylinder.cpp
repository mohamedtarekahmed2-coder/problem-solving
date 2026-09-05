#include <iostream>
#include <queue>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    short op;
    int count;
    ll balls, num_balls, ans;
    bool taken = true;
    queue <pair<ll, ll>> tube;
    cin >> count;
    while (count--)
    {
        cin >> op;
        if (op == 1){
            cin >> balls >> num_balls;
            tube.push({balls, num_balls});
        }else{
            ans = 0;
            cin >> num_balls;
            while(taken){
                if (num_balls <= tube.front().second){
                    ans += tube.front().first * num_balls;
                    tube.front().second -= num_balls;
                    if (tube.front().second == 0) tube.pop();
                    break;
                }else{
                    ans += tube.front().first * tube.front().second;
                    num_balls -= tube.front().second;
                    tube.pop();
                }
            }
            cout << ans << '\n';
        }
    }
    return 0;
}