
#include <bits/stdc++.h>
using namespace std;

#define ll long long

typedef unsigned long long ull;
ull a[501] = {1};  

void solve() {
    int T; 
    cin >> T;
    if (T == 1) {
        cout << "I love Luogu!" << endl;
    } else if (T == 2) {
        cout << 2 + 4 << " " << 10 - 2 - 4 << endl;
    } else if (T == 3) {
        cout << 14 / 4 << endl;
        cout << 14 / 4 * 4 << endl;
        cout << 14 % 4 << endl;
    } else if (T == 4) {
        cout << fixed << setprecision(3) << 500.0 / 3 << endl;
    } else if (T == 5) {
        cout << (260 + 220) / (12 + 20) << endl;
    } else if (T == 6) {
        cout <<  sqrt(6 * 6 + 9 * 9) << endl;
    } else if (T == 7) {
        cout << 100 + 10 << endl;
        cout << 100 + 10 - 20 << endl;
        cout << 0 << endl;
    } else if (T == 8) {
        const double pi = 3.141593;
        int r = 5;
        cout <<  2 * pi * r << endl;
        cout <<  pi * r * r << endl;
        cout <<  4.0 / 3.0 * pi * r * r * r << endl;
    } else if (T == 9) {
        int peaches = 1;
        for (int i = 0; i < 3; ++i) {
            peaches = (peaches + 1) * 2;
        }
        cout << peaches << endl;
    } else if (T == 10) {
        cout << 9 << endl; 
    } else if (T == 11) {
        cout<<1.0*100/3 << endl;
    } else if (T == 12) {
        cout << 'M' - 'A' + 1 << endl;
        cout << char('A' + 18 - 1) << endl;
    } else if (T == 13) {
        const double pi = 3.141593;
        int r1 = 4, r2 = 10;
        double volume1 = 4.0 / 3.0 * pi * r1 * r1 * r1;
        double volume2 = 4.0 / 3.0 * pi * r2 * r2 * r2;
        double total_volume = volume1 + volume2;
        double side = pow(total_volume, 1.0 / 3.0);
        cout << static_cast<int>(side) << endl;
    } else if (T == 14) {
        for (int price = 1; price <= 3500; ++price) {
            if (price * (110 - price + 10) == 3500) {
                cout << price << endl;
                break;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}