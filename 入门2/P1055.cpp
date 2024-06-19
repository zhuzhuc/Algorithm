#include <iostream>
#include <string>
using namespace std;

void solve() {
    string isbn;
    cin >> isbn;
    
    // 提取前9位数字
    string digits;
    for (char ch : isbn) {
        if (ch >= '0' && ch <= '9') {
            digits += ch;
        }
    }
    
    // 计算识别码
    int sum = 0;
    for (int i = 0; i < 9; ++i) {
        sum += (digits[i] - '0') * (i + 1);
    }
    int remainder = sum % 11;
    char correct_check_digit = (remainder == 10) ? 'X' : (remainder + '0');
    
    // 获取输入的识别码
    char input_check_digit = isbn.back();
    
    // 比较识别码并输出结果
    if (input_check_digit == correct_check_digit) {
        cout << "Right" << endl;
    } else {
        isbn.back() = correct_check_digit;
        cout << isbn << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
