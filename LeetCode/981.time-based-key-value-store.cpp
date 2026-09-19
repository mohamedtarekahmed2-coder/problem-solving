#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode id=981 lang=cpp
 *
 * [981] Time Based Key-Value Store
 */

// @lc code=start
class TimeMap
{
    unordered_map<string, vector<pair<int, string>>> time_map;

public:
    TimeMap() = default;

    void set(string key, string value, int timestamp)
    {
        time_map[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp)
    {
        auto it = time_map.find(key);
        if (it == time_map.end())
            return "";
        auto &v = it->second;
        int left = 0, right = ssize(v) - 1;
        string result = "";
        while (left <= right)
        {
            int mid = midpoint(left, right);
            if (timestamp >= v[mid].first)
            {
                result = v[mid].second;
                left = mid + 1;
            }
            else 
            {
                right = mid - 1;
            }
        }
        return result;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end
