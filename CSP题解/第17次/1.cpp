#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;
const int N = 1010;
const double eps = 1e-8;    
int n;
double a[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> a;
    int n,m;
    cin >> n >> m;
    int T  =0;
    int k; 
    int p = -1;
    for(int i = 1; i <= n; i++){
        int toto, sum = 0, x;
        cin >> toto;
        for(int j = 0; j < m; j++){
            cin >> x;
            sum += abs(x);
        }
        T += toto - sum;
        if(sum > p) k = i, p = sum;
    }
    cout << T << " " << k << " " << p << endl;
    return 0;
}