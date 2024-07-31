#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n; 
    cin >> n;
    
    int m = s.length();
    for (int i = 0; i < n; ++i) {
        bool removed = false;
        for (int j = 0; j < s.length() - 1; ++j) {
            if (s[j] > s[j + 1]) {
                s.erase(j, 1);
                removed = true;
                break;
            }
        }
        if (!removed) {
            s.pop_back();
        }
    }
    while (s.length() > 1 && s[0] == '0') {
        s.erase(0, 1);
    }
    
    cout << s << "\n";
}

int main() {
    solve();
    return 0;
}
