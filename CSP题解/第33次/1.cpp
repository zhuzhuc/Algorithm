#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;cin >> n >> m;
    vector<int> cnt(m+1,0);vector<int> res(m+1,0);
    for(int i =0; i < n; i++){
        int l;cin >> l;
        vector<int> w(l);
        unordered_set<int> ww;
        for(int j = 0; j < l; j++){
            cin >> w[j];
            res[w[j]]++;
            ww.insert(w[j]);
        }
        for(int s : ww){
            cnt[s]++;
        }
    }
    for(int i = 1;i <=m; i++) cout << cnt[i] << " " << res[i] << endl;
    return 0;
}