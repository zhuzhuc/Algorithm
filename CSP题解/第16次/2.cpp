#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    getline(cin, s);
    for (int t = 0; t < n; ++t) {
        getline(cin, s);
        vector<int> numbers;
        vector<char> operators;
        for (int i = 0; i < 7; ++i) {
            if (i % 2 == 0) {
                numbers.push_back(s[i] - '0');
            } else {
                operators.push_back(s[i]);
            }
        }
        for (size_t i = 0; i < operators.size();) {
            if (operators[i] == 'x' || operators[i] == '/') {
                int a = numbers[i];
                int b = numbers[i + 1];
                int res;
                if (operators[i] == 'x') {
                    res = a * b;
                } else {
                    if (b == 0) {
                        res = 0;
                    } else {
                        res = a / b;
                    }
                }
                numbers[i] = res;
                numbers.erase(numbers.begin() + i + 1);
                operators.erase(operators.begin() + i);
            } else {
                ++i;
            }
        }
        while (!operators.empty()) {
            int a = numbers[0];
            int b = numbers[1];
            int res;
            if (operators[0] == '+') {
                res = a + b;
            } else {
                res = a - b;
            }
            numbers[0] = res;
            numbers.erase(numbers.begin() + 1);
            operators.erase(operators.begin());
        }
        if (numbers[0] == 24) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
