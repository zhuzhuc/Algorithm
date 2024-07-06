#include <iostream>
#include <vector>
using namespace std;

// 定义每个数字的3x5点阵表示
const vector<vector<string>> digits = {
    {
        "XXX",
        "X.X",
        "X.X",
        "X.X",
        "XXX"
    },
    {
        "..X",
        "..X",
        "..X",
        "..X",
        "..X"
    },
    {
        "XXX",
        "..X",
        "XXX",
        "X..",
        "XXX"
    },
    {
        "XXX",
        "..X",
        "XXX",
        "..X",
        "XXX"
    },
    {
        "X.X",
        "X.X",
        "XXX",
        "..X",
        "..X"
    },
    {
        "XXX",
        "X..",
        "XXX",
        "..X",
        "XXX"
    },
    {
        "XXX",
        "X..",
        "XXX",
        "X.X",
        "XXX"
    },
    {
        "XXX",
        "..X",
        "..X",
        "..X",
        "..X"
    },
    {
        "XXX",
        "X.X",
        "XXX",
        "X.X",
        "XXX"
    },
    {
        "XXX",
        "X.X",
        "XXX",
        "..X",
        "XXX"
    }
};

int main() {
    int n;
    string num;
    cin >> n >> num;


    vector<string> result(5, "");


    for (int i = 0; i < n; ++i) {
        int digit = num[i] - '0';
        for (int j = 0; j < 5; ++j) {
            result[j] += digits[digit][j];
          
            if (i != n - 1) {
                result[j] += ".";
            }
        }
    }


    for (int j = 0; j < 5; ++j) {
        cout << result[j] << endl;
    }

    return 0;
}
