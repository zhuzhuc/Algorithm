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
int count_VK(string s){
	int count = 0;
	for (int _ = 0; _ < s.size(); _++)
	{
		if (s[_] == 'V' and s[_ + 1] == 'K')
		{
			count++;
			_++;
		}
	}
	return count;
}

void solve() {
	string s;
    int n = s.size();
    cin >> n;
    cin >> s;
    int maxVK = count_VK(s);

    for (int i = 0; i < n; ++i)
    {
    	char original = s[i];
    	s[i] = (original == 'V') ? 'K' : 'V';
    	maxVK = max(maxVK, count_VK(s));

    	s[i] = original;
    }
    cout << maxVK << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}