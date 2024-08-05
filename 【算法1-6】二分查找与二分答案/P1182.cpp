#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<map>
#include<iostream>

using namespace std;

class TimeMap {
public:
    map<string, vector<pair<string, int>>> mmp;

    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        mmp[key].push_back({ value,timestamp });
        return;
    }

    string get(string key, int timestamp) {
        if (0 == mmp[key].size()) {
            return "";
        }
        int l = -1, r = mmp[key].size();
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (mmp[key][mid].second < timestamp) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        if (r == mmp[key].size()) {
            return mmp[key][l].first;
        }
        return mmp[key][r].first;
    }
};

int main() {

    TimeMap* obj = new TimeMap();
    obj->set("example", "value1", 10);
    obj->set("example", "value2", 20);

    cout << obj->get("example", 30) << endl;  // 应该输出: "value2"
    cout << obj->get("example", 25) << endl;  // 应该输出: "value2"
    cout << obj->get("example", 21) << endl;  // 应该输出: "value2"

    return 0;
}