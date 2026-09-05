#include <iostream>
#include <vector>
#include <stack>
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

struct operation_type{
    int type_op;
    int num_chars;
    string text;
};

stack<operation_type> backup;
string str = "";

void append(const string &s)
{
    str += s;
}

void del(int count)
{
    str.erase(str.size() - count);
}

void print_char()
{
    int index;
    cin >> index;
    cout << str[index - 1] << '\n';
}

void backup_delete(int num_char_append)
{
    backup.push({2, num_char_append, ""});
}

void backup_append(const string &s)
{
    backup.push({1, 0, s});
}

void get_backup()
{
    operation_type op = backup.top();
    if (op.type_op == 1)
        append(op.text);
    else
        del(op.num_chars); 
    backup.pop();
}

void solve()
{
    int num_op;
    cin >> num_op;
    while (num_op--)
    {
        int operation;
        cin >> operation;
        switch (operation)
        {
        case 1:
        {
            string s;
            cin >> s;
            backup_delete(static_cast<int>(s.size()));
            append(s);
            break;
        }
        case 2:
        {
            int count;
            cin >> count;
            string deleted_part = str.substr(str.size() - count);
            backup_append(deleted_part);
            del(count);
            break;
        }
        case 3:
        {
            print_char();
            break;
        }
        default:
            get_backup();
            break;
        }
    }
}

int main()
{
    fast_io();
    solve();

    return 0;
}