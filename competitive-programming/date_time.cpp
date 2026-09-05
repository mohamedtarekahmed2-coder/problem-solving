#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

struct type_d
{
    int year;
    int mon;
    int day;
};

struct type_t
{
    int hour;
    int min;
    int sec;
};

struct time_now
{
    time_t total = time(0) + 3 * 60 * 60;

    type_t get_time()
    {
        int total_ver = (int)total;
        type_t t;

        t.sec = total_ver % 60;
        total_ver /= 60;

        t.min = total_ver % 60;
        total_ver /= 60;

        t.hour = total_ver % 24;
        total_ver /= 24;
        
        return t;
    }
};

struct date
{
    int year = 1970, mon = 1, day = 1;
    time_t total = time(0) + 3 * 60 * 60;
    int total_days;

    bool leap(int y)
    {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    int get_year()
    {
        int total_sec = (int) total;
        while(true)
        {
            bool is_leap = leap(year);

            int days_in_year = is_leap ? 366 : 365;
            int sec_in_year = days_in_year * 24 * 60 * 60;

            if (total_sec >= sec_in_year)
            {
                total_sec -= sec_in_year;
                year++;
            }
            else break;
        }
        total_days = total_sec;
        return year;
    }

    int get_month(int yr)
    {
        mon = 1, day = 1;
        total_days /= (60 * 60 * 24);
        int days_in_month [12] = {31, (leap(yr) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        for (int i = 0; i < 12 && total_days >= days_in_month[i]; i++)
        {
            total_days -= days_in_month[i];
            mon++;
        }
        day += total_days;
        return mon;
    }

    type_d get_date()
    {
        type_d now;
        now.year = get_year();
        now.mon = get_month(now.year);
        now.day = day;
        return now;
    }
};

void date_time()
{
    date d;
    time_now tn;
    type_d td = d.get_date();
    type_t tt = tn.get_time();
    cout << td.year << "/" << td.mon << "/" << td.day << "\n";
    cout << tt.hour << ":" << tt.min << ":" << tt.sec << "\n";
}

int main()
{

    return 0;
}