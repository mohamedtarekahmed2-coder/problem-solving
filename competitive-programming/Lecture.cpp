#include <iostream>
#include <vector>
#include <map>
using namespace std;

void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void read_translation(map <string, string> &langs, int word_langs) 
{
    string lang_1, lang_2;
    while (word_langs--)
    {
        cin >> lang_1 >> lang_2;
        langs.insert({lang_1, lang_2});
    }
}

void read_vector(vector <string> &word_lec)
{
    for (int i = 0; i < word_lec.size(); i++)
        cin >> word_lec.at(i);
}

void print_answer(map <string, string> &trans, const vector <string> &lec)
{
    for (int i = 0; i < static_cast<int>(lec.size()); i++)
    {
        if(lec.at(i).size() <= trans[lec.at(i)].size())
            cout << lec.at(i) << ' ';
        else
            cout << trans[lec.at(i)] << ' ';
    }
    cout << '\n';
}

int main()
{
    fast_io();

    int word_lec, word_langs;
    cin >> word_lec >> word_langs;

    map <string, string> trans;
    read_translation(trans, word_langs);

    vector <string> lec(word_lec, "");
    read_vector(lec);

    print_answer(trans, lec);

    return 0;
}