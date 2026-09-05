#include <iostream>
#include <queue>
#include <iomanip> 
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

struct funcs
{
    priority_queue <float> min_half;
    priority_queue <float, vector<float>, greater<float>> max_half;
    
    void read_val()
    {
        int val;
        cin >> val;
        if (val >= min_half.top())
            max_half.push(val);
        else 
            min_half.push(val);
    }

    void balance()
    {
        if (max_heap.size() > min_heap.size() + 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        } 
        else if (min_heap.size() > max_heap.size() + 1) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }

    void print_answer()
    {
        if (min_half.size() == max_half.size())
            cout << (min_half.top() + max_half.top()) / 2 << '\n';
        else if(min_half.size() > max_half.size())
            cout << min_half.top() << '\n';
        else 
            cout << max_half.top() << '\n';
    }
    
    void solve ()
    {
        read_val();
        balance();
        print_answer();
    }
};

int main()
{
    fast_io();
    
    funcs functions;
    
    int num_size;
    cin >> num_size;
    
    float first_val;
    cin >> first_val;
    cout << fixed << setprecision(1);
    cout << first_val << '\n';

    functions.min_half.push(first_val);

    while (1 < num_size--)
    {
        functions.solve();
    }
    return 0;
}