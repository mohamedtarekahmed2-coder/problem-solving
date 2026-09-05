#include <iostream>
#include <map>
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void make_letter_map(map<char, char> &shift_map, char shifting)
{
    string keyboard_letters = " qwertyuiopasdfghjkl;zxcvbnm,./ ";
    if (shifting == 'R'){
        for (int i = 0; i + 1 < keyboard_letters.size(); i++)
        {
            shift_map.insert({keyboard_letters.at(i + 1), 
                keyboard_letters.at(i)});
        }
    }
    else {
        for (int i = 1; i < keyboard_letters.size(); i++)
        {
            shift_map.insert({keyboard_letters.at(i - 1), 
                keyboard_letters.at(i)});
        }
    }
}

void print_answer (map<char, char> &shift_map, string &s)
{
    for (int i = 0; i < s.size(); i++)
        cout << shift_map.at(s.at(i));
    cout << '\n';
}

int main()
{
    fast_io();
    string str;
    char shifting;
    cin >> shifting >> str;

    map<char, char> shift_map;
    make_letter_map(shift_map, shifting);
    print_answer(shift_map, str);

    return 0;
}