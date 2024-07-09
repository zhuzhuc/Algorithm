#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back

const int maxn = 2e5 + 2;
const int maxm = 62;

void solve() {
    string tar, art;
    getline(cin, tar);
    getline(cin, art);
    transform(tar.begin(), tar.end(), tar.begin(), ::tolower);
    transform(art.begin(), art.end(), art.begin(), ::tolower);
    tar = ' ' + tar + ' ';
    art = ' ' + art + ' ';
    if (art.find(tar) == string::npos) {cout << -1 << "\n"; }else {int first_position = art.find(tar);int pos = first_position;int count = 0;while (pos != string::npos) {count++;pos = art.find(tar, pos + 1);}cout << count << " " << first_position << "\n";}  
}         
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
