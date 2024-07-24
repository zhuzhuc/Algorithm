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

bool isLeapYear(int year) {
    if (year % 400 == 0) {
        return true;
    } else if (year % 100 == 0) {
        return false;
    } else if (year % 4 == 0) {
        return true;
    } else {
        return false;
    }
}

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true; 
    if (n % 2 == 0) return false; 
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

string multiply(string num1, int num2) {
    int carry = 0;
    for (int i = num1.size() - 1; i >= 0; --i) {
        int product = (num1[i] - '0') * num2 + carry;
        num1[i] = (product % 10) + '0';
        carry = product / 10;
    }
    while (carry) {
        num1.insert(num1.begin(), (carry % 10) + '0');
        carry /= 10;
    }
    return num1;
}

string factorial(int n) {
    string result = "1";
    for (int i = 2; i <= n; ++i) {
        result = multiply(result, i);
    }
    return result;
}

int count_digit(const string& number, char digit) {
    return count(number.begin(), number.end(), digit);
}

typedef std::vector<int> vi;
typedef vector<vi> vvi;
vi read_ints(int n){
	vi res(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> res[i];
	}
	return res;
}
vvi read_ma(int n, int m){
	vvi res(n);
	for (int i = 0; i < n; ++i)
	{
		res[i] = read_ints(m);
	}
	return res;
}
void solve() {
    int n,m;
    cin >> n >> m;
    vvi a = read_ma(n,  m), b = read_ma(n,m);
    int nm = n * m;
    vi pos1i(nm), pos2i(nm), pos1j(nm), pos2j(nm);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x = a[i][j] - 1;
            int y = b[i][j] - 1;
            pos1i[x] = pos2i[y] = i;
            pos1j[x] = pos2j[y] = j;
        }
    }
    vector<set<int>> pi(nm), pj(nm);
    for (int x = 0; x < nm; ++x) {
        int i1 = pos1i[x], i2 = pos2i[x];
        int j1 = pos1j[x], j2 = pos2j[x];
        pi[i1].insert(i2);
        pj[j1].insert(j2);
    }
    for (int x = 0; x < nm; ++x) {
        if (pi[x].size() > 1 || pj[x].size() > 1) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;cin >> t; 

    for (int i = 0; i < t; ++i)
    {
    	/* code */solve();
    }
    	
    return 0;
}
