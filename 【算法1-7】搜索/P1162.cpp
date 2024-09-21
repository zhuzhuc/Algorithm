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
int n;
std::vector<vector<int>> v;
vector<vector<bool>> vis;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool isB(int x, int y){
	return x >= 0 and x < n and y >= 0 and y < n;
}
void dfs(int x, int y){
	vis[x][y] = true;
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(isB(nx, ny) and !vis[nx][ny] and v[nx][ny] == 0){
			dfs(nx, ny);
		}
	}
}
void solve() {
    cin >> n;
    v.resize(n, vector<int>(n));
    vis.resize(n, vector<bool>(n, false));

    for(int i = 0; i < n; i++){
    	for(int j = 0; j < n; j++){
    		cin >> v[i][j];
    	}
    }
    for(int i = 0; i < n; i++){
    	if(v[i][0] == 0 and !vis[i][0]){
    		dfs(i, 0);
    	}
    	if(v[i][n - 1] == 0 and !vis[i][n - 1]){
    		dfs(i, n - 1);
    	}
    }
    for(int j = 0; j < n; j++){
    	if(v[0][j] == 0 and !vis[0][j]){
    		dfs(0, j);
    	}
    	if(v[n - 1][j] == 0 and !vis[n - 1][j]){
    		dfs(n - 1, j);
    	}
    }
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < n; j++){
    		if(v[i][j] == 0 and !vis[i][j]){
    			v[i][j] = 2;
    		}
    	}
    }
    for(int i = 0; i < n; i++){
    	for(int j = 0; j< n; j++){
    		cout << v[i][j] << " ";
    	}
    	cout << endl;
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
