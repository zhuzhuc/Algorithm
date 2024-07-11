#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string s[100001];
int a[100001], b[100001], a2[100001], b2[100001];

bool check(int x) {
    int t = s[x].size();
    for(int i = 0; i < t; i++)
        if(s[x][i] == 'E')
            return false;
    return true;
}

int main() {
    int n = 1, i, j, t = 1, t2 = 1;
    cin >> s[n];
    while(check(n)) {
        n++;
        cin >> s[n];
    }

    for(i = 1; i <= n; i++) {
        int sz = s[i].size();
        for(j = 0; j < sz; j++) {
            if(s[i][j] == 'E') {

                for(int k = 1; k <= t; k++) {
                    cout << a[k] << ":" << b[k] << endl;
                }
                cout << endl;
                for(int k = 1; k <= t2; k++) {
                    cout << a2[k] << ":" << b2[k] << endl;
                }
                return 0;
            }

            if(s[i][j] == 'W') {
                a[t]++;
                a2[t2]++;
            } else if(s[i][j] == 'L') {
                b[t]++;
                b2[t2]++;
            }

            if((a[t] >= 11 || b[t] >= 11) && abs(a[t] - b[t]) >= 2) {
                t++;
            }

            if((a2[t2] >= 21 || b2[t2] >= 21) && abs(a2[t2] - b2[t2]) >= 2) {
                t2++;
            }
        }
    }

    return 0;
}