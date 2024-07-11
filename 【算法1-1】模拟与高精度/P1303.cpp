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
    for (int i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) return false;}
    return true;
}
unsigned long long factorial(int n) {
    if (n == 0) {
        return 1; 
    }
    return n * factorial(n - 1);
}
char a1[10001],b1[10001];
int a[10001],b[10001],i,x,len,j,c[10001];
void solve() {
     cin>>a1>>b1;
    int lena=strlen(a1);
    int lenb=strlen(b1);
    for(i=1;i<=lena;i++)a[i]=a1[lena-i]-'0';
    for(i=1;i<=lenb;i++)b[i]=b1[lenb-i]-'0';
    for(i=1;i<=lenb;i++)
    for(j=1;j<=lena;j++)
    c[i+j-1]+=a[j]*b[i];
    for(i=1;i<lena+lenb;i++)
    if(c[i]>9)
    {
        c[i+1]+=c[i]/10;
        c[i]%=10;
    }
    len=lena+lenb;
    while(c[len]==0&&len>1)len--;
    for(i=len;i>=1;i--)cout<<c[i];
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}