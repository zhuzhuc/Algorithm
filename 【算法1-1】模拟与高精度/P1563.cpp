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

struct P1563
{
    int head;
    string name;
}a[100005];
int n,m,x,y;
void solve()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].head>>a[i].name;
    }
    int now=0;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        if(a[now].head==0&&x==0)now=(now+n-y)%n;
        else if(a[now].head==0&&x==1)now=(now+y)%n;
        else if(a[now].head==1&&x==0)now=(now+y)%n;
        else if(a[now].head==1&&x==1)now=(now+n-y)%n;
    }
    cout<<a[now].name<<endl;

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}