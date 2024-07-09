#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back

const int maxn = 2e5 + 2;
const int maxm = 62;

string removefront_0(string s){
    s.erase(0, min(s.find_first_not_of('0'), s.size()-1));
    return s;
}

string removefinal_0(string s){
    s.erase(s.find_last_not_of('0') + 1, string::npos);
    return s;
}

string reverseString(string s){
    reverse(s.begin(), s.end());
    return s;
}

void solve() {
    string s;
    cin >> s;

    if (s.find('.') != string::npos) {
        size_t dotPos = s.find('.');
        string intPart = s.substr(0, dotPos);
        string decPart = s.substr(dotPos + 1);

        intPart = reverseString(intPart);
        decPart = reverseString(decPart);

        intPart = removefront_0(intPart);
        decPart = removefinal_0(decPart);

        if (decPart == "") {
            decPart = "0";
        }

        cout << intPart << "." << decPart << endl;

    } else if (s.find('/') != string::npos) {
        size_t slashPos = s.find('/');
        string numerator = s.substr(0, slashPos);
        string denominator = s.substr(slashPos + 1);

        numerator = reverseString(numerator);
        denominator = reverseString(denominator);

        numerator = removefront_0(numerator);
        denominator = removefront_0(denominator);  

        cout << numerator << "/" << denominator << endl;

    } else if (s.find('%') != string::npos) {
        string number = s.substr(0, s.length() - 1);
        number = reverseString(number);
        number = removefront_0(number);
        cout << number << "%" << endl;

    } else {
        s = reverseString(s);
        s = removefront_0(s);  
        cout << s << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
