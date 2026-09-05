#include <iostream>
#include <vector>
#include <climits>
#include <map>
#include <unordered_map>
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

//  * take pairs
vector<pair<int, int>> read_vector_pair()
{
    vector<pair<int, int>> vp;
    int size, front, back;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cin >> front >> back;
        vp.push_back(make_pair(front, back));
    }
    return vp;
}

//  * make unordered map of pairs to take the freqs in front and back
unordered_map<int,pair<int, int>> make_freqs(vector<pair<int, int>> &cards)
{
    unordered_map<int,pair<int, int>>freqs_f_b;
    for (auto pr : cards)
    {
        if (pr.first == pr.second)
            freqs_f_b[pr.first].first++;
        else {
            freqs_f_b[pr.first].first++;
            freqs_f_b[pr.second].second++;
        }
    }
    return freqs_f_b;
}

void print_answer(vector<pair<int, int>> &cards ,unordered_map<int,pair<int, int>> &freqs_fb)
{
    int ans = INT_MAX, half = ((int)cards.size() + 1) / 2;
    int flip = 0;

    for (auto& [number, counts] : freqs_fb)
    {
        //  * make loop in front to get the min num you need to be half or more
        if(counts.first + counts.second >= half)
        {
            flip = half - counts.first;
            if (flip < ans)
                ans = flip;
        }
    }
    if (ans == INT_MAX)
        cout << "-1\n";
    else if (ans < 0)
        cout << 0 << '\n';
    else 
        cout << ans << '\n';
}

void solve()
{
    //  * Make vector to pairs
    vector<pair<int, int>> cards = read_vector_pair();
    unordered_map<int,pair<int, int>> freqs_front_back = make_freqs(cards);
    print_answer(cards, freqs_front_back);
}
  
int main()
{
    fast_io();

    int test_cases = 1;
    // cin >> test_cases;
    while (test_cases--)
    {
        solve();
    }

    return 0;
}