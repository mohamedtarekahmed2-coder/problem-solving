#include <iostream>
#include <vector>
using namespace std;
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
}
struct BreedCounts
{
    int holsteins = 0;
    int guernseys = 0;
    int jerseys = 0;
};

vector<BreedCounts> build_prefix(int size)
{
    vector<BreedCounts> pre_breeds(size + 1, {0, 0, 0});

    int breed;
    for (int i = 1; i < (int)pre_breeds.size(); i++)
    {
        cin >> breed;

        if (breed == 1)
            pre_breeds[i].holsteins++;
        else if(breed == 2)
            pre_breeds[i].guernseys++;
        else 
            pre_breeds[i].jerseys++;
        pre_breeds[i].holsteins += pre_breeds[i - 1].holsteins;
        pre_breeds[i].guernseys += pre_breeds[i - 1].guernseys;
        pre_breeds[i].jerseys += pre_breeds[i - 1].jerseys;
    }
    
    return pre_breeds;
}

void print_answer(const vector<BreedCounts> &pre_breed, int start, int end)
{
    cout << pre_breed[end].holsteins - pre_breed[start - 1].holsteins << ' ';
    cout << pre_breed[end].guernseys - pre_breed[start - 1].guernseys << ' ';
    cout << pre_breed[end].jerseys - pre_breed[start - 1].jerseys << '\n';
}

int main()
{
    fast_io();

    int num_cows; cin >> num_cows;
    int num_query;  cin >> num_query;

    vector<BreedCounts> prefix_breed_counting = build_prefix(num_cows);

    int start, end;
    while (num_query--)
    {
        cin >> start >> end;
        print_answer(prefix_breed_counting, start, end);
    }
    
    return 0;
}