#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<stack>
#include<queue>
#include<map>
using namespace std;
const int M = 10010;
int main(){
    int n; cin >> n;
    int a[500010];
    int b[M];
    for(int i = 1; i <= n; i++) cin >> a[i];
    n = unique(a + 1, a  + n + 1) -a - 1;
    a[0] = a[n + 1] = 0;
    for(int i = 1; i <= n; i ++){
        int x =a[i - 1], y = a[i], z = a[i + 1];
        if(x < y  and z < y){
            b[y]++;
        }
        else if(x > y and z > y) b[y]--;
    }
    int res, sum = 0;
    for(int i  = M - 1; i; i --){
        sum += b[i];
        res = max(res, sum);
    }
    cout <<res << endl;
    return 0;
}