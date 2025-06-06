// #include <iostream>
// #include <vector>
// #include <string>

// using namespace std;

// int main() {
//     int n;
//     cin >> n;
//     string s;
//     getline(cin, s);
//     for (int t = 0; t < n; ++t) {
//         getline(cin, s);
//         vector<int> numbers;
//         vector<char> operators;
//         for (int i = 0; i < 7; ++i) {
//             if (i % 2 == 0) {
//                 numbers.push_back(s[i] - '0');
//             } else {
//                 operators.push_back(s[i]);
//             }
//         }
//         for (size_t i = 0; i < operators.size();) {
//             if (operators[i] == 'x' || operators[i] == '/') {
//                 int a = numbers[i];
//                 int b = numbers[i + 1];
//                 int res;
//                 if (operators[i] == 'x') {
//                     res = a * b;
//                 } else {
//                     if (b == 0) {
//                         res = 0;
//                     } else {
//                         res = a / b;
//                     }
//                 }
//                 numbers[i] = res;
//                 numbers.erase(numbers.begin() + i + 1);
//                 operators.erase(operators.begin() + i);
//             } else {
//                 ++i;
//             }
//         }
//         while (!operators.empty()) {
//             int a = numbers[0];
//             int b = numbers[1];
//             int res;
//             if (operators[0] == '+') {
//                 res = a + b;
//             } else {
//                 res = a - b;
//             }
//             numbers[0] = res;
//             numbers.erase(numbers.begin() + 1);
//             operators.erase(operators.begin());
//         }
//         if (numbers[0] == 24) {
//             cout << "Yes\n";
//         } else {
//             cout << "No\n";
//         }
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

stack<int> num;
stack<char> op;

void eval(){
     int b = num.top(); num.pop();
     int a = num.top(); num.pop();
     char c = op.top(); op.pop();
     int x;
     if(c == '+') x = a + b;
     else if(c == '-') x= a - b;
     else if(c == 'x') x = a * b;
     else{
         if(a * b >= 0) x = a /b;
         else{
             if(a % b == 0) x = a/ b;
             else x = a / b -1;
         }
     }

    num.push(x);
}

int main(){
    unordered_map<char, int> pr;
    pr['+'] = pr['-'] = 1;
    pr['x'] = pr['/'] = 2;
    int n;
    scanf("%d", &n);
    while(n --){
        string s;
        cin >> s;
        num = stack<int> ();
        op = stack<char> ();
        for(auto c : s){
            if(c >='0' and c <= '9') num.push(c - '0');
            else{
                while(op.size() and pr[op.top()] >= pr[c]) eval();
                op.push(c);
            }
        }  
        while(op.size()) eval();
        if(num.top() == 24) puts("Yes");
        else puts("No");
    }
    return 0;
}