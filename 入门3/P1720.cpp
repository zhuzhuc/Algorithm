#include <bits/stdc++.h>
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back

const int maxn = 2e5 + 2;
const int maxm = 62;
void solve(){
    int n;
    cin >> n;

    const double sqrt5 = sqrt(5.0);
    const double phi = (1.0 + sqrt5) / 2.0;
    const double psi = (1.0 - sqrt5) / 2.0;

    double Fn = (pow(phi, n) - pow(psi, n)) / sqrt5;

    cout << fixed << setprecision(2) << Fn << endl;


}
int main(int argc, char const *argv[])
{   

    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
