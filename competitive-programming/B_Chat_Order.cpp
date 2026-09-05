#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void print_latest_unique(const vector <string>& messages){
    unordered_set<string> done;
    for (int i = static_cast<int>(messages.size()) - 1; i >= 0; i--)
    {
        if (!done.count(messages.at(i))){
            done.insert(messages.at(i));
            cout << messages.at(i) << '\n';
        }
    }
}

void take_input(vector <string>& messages)
{
    for (int i = 0; i < messages.size(); i++)
        cin >> messages.at(i);
}

int main()
{
    fast_io();

    int num_messages;
    cin >> num_messages;
    vector <string> messages(num_messages, "");
    take_input(messages);
    print_latest_unique(messages);

    return 0;
}