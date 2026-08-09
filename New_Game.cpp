#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void Fast_IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

struct num_freq
{
    int num, freq;
};


vector<num_freq> ReadVector(int size)
{
    vector<int> v(size, 0);
    for(int &i : v)
        cin >> i;

    sort(v.begin(), v.end());

    vector<num_freq>nf;
    nf.push_back({v.front(), 1});

    for (int i = 1; i < size; i++)
    {
        if (v[i] == nf.back().num)
            nf.back().freq++;
        else 
            nf.push_back({v[i], 1});
    }
    
    return nf;
}

void Solve()
{
    int num_cards, max_distinct;
    cin >> num_cards >> max_distinct;
    
    vector<num_freq> nf = ReadVector(num_cards);

    int answer = nf[0].freq, current_answer = nf[0].freq;
    int ptr1 = 0;

    for (int ptr2 = 1; ptr2 < nf.size(); ptr2++)
    {
        if (nf[ptr2].num == nf[ptr2 - 1].num + 1)
        {
            if (ptr2 - ptr1 < max_distinct)
            {
                current_answer += nf[ptr2].freq;
            }
            else
            {
                ptr1++;
                current_answer += nf[ptr2].freq - nf[ptr1 - 1].freq;
            }
        }
        else
        {
            ptr1 = ptr2;
            current_answer = nf[ptr1].freq;
        }
        answer = max(answer, current_answer);
    }
    cout << answer << '\n';
}

int main()
{
    Fast_IO();

    int test_cases = 1;
    cin >> test_cases;
    while (test_cases--)
    {
        Solve();
    }

    return 0;
}