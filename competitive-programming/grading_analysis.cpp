#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>  
#include <iomanip>
using namespace std;

ifstream fin("hu_data.txt");

bool even(int num){
    if (num % 2 == 0)
        return 1;
    else
        return 0;
}

struct grading_analysis
{
    int size;
    vector <int> data_;
    vector <int> freq;

    void read_data_and_sort()
    {
        int num;
        for (int i = 0; i < size; i++)
        {
            fin >> num;
            data_.push_back(num);
        }
        sort(data_.begin(), data_.end());
    }

    void make_freq()
    {
        freq.resize(41);
        for (int i = 0; i < size; i++)
            freq.at(data_.at(i))++;
    }

    float mean()
    {
        int sum = 0;
        for (int i = 0; i < 41; i++)
            sum += (freq.at(i) * i);
        return (float)sum / size;
    }

    int median(){
        int num;
        if (even(size))
        {
            num = (size / 2) - 1;
            return (data_.at(num) + data_.at(num + 1)) / 2;
        }
        else {
            num = size / 2;
            return data_.at(num);
        }
    }

    vector <int> mode(){
        int max = -1;
        vector <int> modes;
        for (int i = 0; i < 41; i++)
        {
            if (max == freq.at(i))
            {
                modes.push_back(i);
                max = freq.at(i);
            }
            else if (max < freq.at(i))
            {
                modes.clear();
                modes.push_back(i);
                max = freq.at(i);
            }
        }
        return modes;
    }

    void print_location_measures(int mean, int median, vector <int> &modes)
    {
        cout << "==============================================================\n";
        cout << "Mean = " << mean << '\n';
        cout << "Median = " << median << '\n';
        cout << ((modes.size() > 1)? "Modes = " : "Mode = ");
        for (int &mode : modes)
            cout << mode << ' ';
        cout << "\n==============================================================\n";
    }

    void location_measures(){
        int mean_ = mean();
        int median_ = median();
        vector <int> modes = mode();
        print_location_measures(mean_, median_, modes);
    }

    void IQR()
    {
        int Q1_index = size / 4;
        int Q1 = data_[Q1_index];
        int Q3_index = (size * 3) / 4;
        int Q3 = data_[Q3_index];
        int IQR = Q3 - Q1;
        cout << "IQR = " << IQR << '\n';
        cout << "LB = " << Q1 - (float)IQR * 1.5  << ", " << "UB = " << Q3 + (float)IQR * 1.5 << '\n';
    }

    void dispersion_measures(){
        int Range = data_.back() - data_.front();
        cout << "Range = " << Range << '\n';
        IQR();
        cout << "==============================================================\n";
    }

    void max_min()
    {
        for (int i = 0; i < 41; i++)
        {
            if (freq.at(i) != 0){
                cout << "Min = " << i << '\n';
                break;
            }
        }
        for (int i = 40; i >= 0; i--)
        {
            if (freq.at(i) != 0){
                cout << "Max = " << i << '\n';
                break;
            }
        }
        cout << "==============================================================\n";
    }

    void freqs_in_100()
    {
        cout << "Grades & Freqs & Freqs% " << '\n';
        for (int i = 0; i < 41; i++)
        {
            cout << i;
            if (i < 10)
                cout << "  : ";
            else 
                cout << " : ";
            cout << freq.at(i);
            if (freq.at(i) < 10)
                cout << "   : ";
            else if (freq.at(i) < 100)
                cout << "  : "; 
            else
                cout << " : ";
            cout << ((float)freq.at(i) / size) * 100 << '%';
            cout << '\n';
        }
        cout << "\n==============================================================\n";
        for (int i = 0; i < 41; i++)
        {
            cout << i;
            if (i < 10)
                cout << "  : ";
            else 
                cout << " : ";
            int count = (((float)freq.at(i)) / size) * 100;
            for (int i = 0; i < count; i++)
                cout << '*';
            cout << '\n';
        }
        cout << "==============================================================\n";
    }
};





int main()
{
    grading_analysis analysis;
    fin >> analysis.size;

    analysis.read_data_and_sort();
    analysis.make_freq();
    analysis.location_measures();
    analysis.dispersion_measures();
    analysis.max_min();
    analysis.freqs_in_100();
    
    return 0;
}