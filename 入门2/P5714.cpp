
#include <bits/stdc++.h>
using namespace std;

#define ll long long

typedef unsigned long long ull;
ull a[501] = {1};  

void solve() {
    double x;
    double a,bmi;
    cin >> x >> a;
    bmi = x / (a * a);
    if (bmi < 18.5) cout << "Underweight" << endl;
    if (bmi >= 18.5 && bmi < 24)
        cout << "Normal";
    if (bmi >= 24)
        cout << bmi << endl << "Overweight" << endl;
} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}