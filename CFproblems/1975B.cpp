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

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

bool is_beautiful(const vector<int>& arr) {
    unordered_set<int> elements(arr.begin(), arr.end());

    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int g = gcd(arr[i], arr[j]);
            if (elements.find(g) == elements.end()) {
                return false;
            }
        }
    }
    return true;
}
const int N = 1e5+10;
int a[N];
void solve() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int fl=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]==1)fl=1;
        }
        if(fl)cout<<"Yes\n";
        else{
            sort(a+1,a+1+n);
            vector<int> b;
            for(int i=2;i<=n;i++){
                if(a[i]%a[1])b.push_back(a[i]);
            }
            sort(b.begin(),b.end());
            n = b.size();
            for(int j=1;j<n;j++){
                if(b[j]%b[0]){
                    fl=1;
                    break;
                }
            }
            if(!fl)cout<<"Yes\n";
            else cout<<"No\n";
        }

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
