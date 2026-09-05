#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void operation_1(vector <queue<pair<int, int>>>& queues, int time_in){
    int num_people, num_queue;
    cin >> num_people >> num_queue;
    queues.at(num_queue - 1).push({num_people, time_in});
}

void operation_2(vector <queue<pair<int, int>>>& queues,vector <int> &answer, int &max_out){
    int num_queue;
    cin >> num_queue;
    int time_out = queues.at(num_queue - 1).front().second;
    if (max_out > time_out)
        answer.push_back(queues.at(num_queue - 1).front().first);
    else
        max_out = time_out;
    queues.at(num_queue - 1).pop();
}

void print_vector(vector <int> &v){
    cout << v.size() << '\n';
    for (int i = 0; i < v.size(); i++)
        cout << v.at(i) << ' ';
}

void solve(int num_peoples, int num_queues){
    vector <queue<pair<int, int>>> queues(num_queues);
    vector <int> answer;
    int num_operations = 2 * num_peoples, operation, max_out = 0, time_in = 0;
    while (num_operations--)
    {
        cin >> operation;
        switch (operation)
        {
        case 1:
            operation_1(queues, ++time_in);
            break;
        default:
            operation_2(queues, answer, max_out);
            break;
        }
    }
    sort(answer.begin(), answer.end()); 
    print_vector(answer);
}

int main() {
    fast_io();

    int test_cases = 1;
    // cin >> test_cases;
    while (test_cases--)
    {
        int num_peoples, num_queues;
        cin >> num_peoples >> num_queues;
        solve(num_peoples, num_queues);
    }
    
    return 0;
} 