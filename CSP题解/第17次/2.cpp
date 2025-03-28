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
vector<int> q[N];
bool st[N];

int get(vector<int>& q, int k){
    if(k >= q.size()){
        return 0;
    }
    int res = q[k];
    for(int i = k + 1; i < q.size(); i++){
        if(q[i] < 0){
            res += q[i];
        }
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    if (n > N-1) {
        cout << "n exceeds the maximum size allowed." << endl;
        return 0;
    }
    for(int i = 0; i < n; i++){
        int k; cin >> k;
        while(k--){
            int x; cin >> x;
            q[i].push_back(x);
            st[x] = true;
            if (x >= 0 && x < N) st[x] = true;
        }
    }
    int T = 0, D = 0, E = 0;
    for(int i = 0; i < n; i++){
        int a,b;
        for(int j = q[i].size() - 1; j >= 0; j--){
            if(q[i][j] > 0){
                a = get(q[i], j);
                break;
            }
        }
        b = get(q[i], 0);
        T += a;
        if(b > a){
            st[i] = true;
            D++;
        }
    }
    for(int i = 0; i < n; i++){
        if(st[i] and st[(i+1)%n] and st[(i+2)%n]){
            E++;
        }
    }
    cout << T << " " << D << " " << E << endl;

    return 0;
}