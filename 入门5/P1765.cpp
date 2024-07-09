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
void solve() {
	unordered_map<char, int> keyPresses = {
        {'a', 1}, {'b', 2}, {'c', 3},
        {'d', 1}, {'e', 2}, {'f', 3},
        {'g', 1}, {'h', 2}, {'i', 3},
        {'j', 1}, {'k', 2}, {'l', 3},
        {'m', 1}, {'n', 2}, {'o', 3},
        {'p', 1}, {'q', 2}, {'r', 3}, {'s', 4},
        {'t', 1}, {'u', 2}, {'v', 3},
        {'w', 1}, {'x', 2}, {'y', 3}, {'z', 4},
        {' ', 1}
    };
    string s;
    getline(cin, s);
    int sum = 0;
    for (char c : s)
    {
    	sum += keyPresses[c];
    }
    cout << sum << "\n";
    
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}