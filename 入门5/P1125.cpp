#include <bits/stdc++.h>
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

#define ll long long
#define ff first
#define pb push_back
#define eb emplace_back

const int maxn = 2e5 + 2;
const int maxm = 62;

bool isPrime(int num){
    if(num < 2) return false;
    for(int _ = 2; _ * _ <= num; ++_) { if(num % _ == 0) {return false;}}
    return true;
}

void solve() {
    string s;  
    cin >> s;
    vector<int> freq(26, 0);
    for(char c : s) freq[c - 'a']++;
    int maxn = *max_element(freq.begin(), freq.end());
    int minn = INT_MAX;
    for(int count : freq) {if(count > 0 && count < minn) { minn = count; }}
    int diff = maxn - minn;
    if(isPrime(diff)) {cout << "Lucky Word" << "\n";cout << diff << "\n";}
     else {cout << "No Answer" << "\n";cout << 0 << "\n";}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
