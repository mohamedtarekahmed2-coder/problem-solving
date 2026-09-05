#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void read_vector(vector<int> &particles, int num)
{
    for (int i = 0; i < num; i++)
    {
        cin >> particles[i];
    }
}

int main()
{
    fast_io();

    int num_particles;
    int min_time = 1e9;
    string moves;

    cin >> num_particles >> moves;

    vector<int> particles(num_particles);
    read_vector(particles, num_particles);

    for (int i = 0; i < num_particles - 1; i++)
    {
        if (moves[i] == 'R' && moves[i + 1] == 'L')
        {
            int current_time = (particles[i + 1] - particles[i]) / 2;
            if (min_time > current_time)
                min_time = current_time;
        }
    }

    cout << (min_time == 1e9 ? -1 : min_time) << '\n';

    return 0;
}