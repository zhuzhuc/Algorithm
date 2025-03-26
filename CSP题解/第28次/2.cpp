#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// a +t - i
// a + t 天开始训练
//
int n,m;
int main() {
    cin >> n >> m;
    vector<int> a(m);
    vector<int> b(m);
    for(int i = 1; i <= m; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
    vector<int> earlist(m + 1);
    for(int i = 1; i <= m; i++){
        if(a[i] == 0) earlist[i] = 1;
        else earlist[i] = earlist[a[i]] + b[a[i]];
    }
    for(int i = 1; i <= m; i++){
        cout << earlist[i] << " ";
    }
    cout << endl;
    bool cando = true;
    for(int i = 1; i <= m; i++){
        if(earlist[i] + b[i] - 1> n) {
            cando = false;
            break;
        }
    }
    if(!cando){
        return 0;
    } 
    vector<int> last(m + 1);
    for(int i = m; i >= 1; i--){
        if(earlist[i] + b[i] - 1 == n) last[i] = earlist[i];
        else{
            int min_s = n - b[i] + 1;
            for(int j = i + 1; j <= m; j++){
                if(a[j] == i) min_s = min(min_s, last[j] - b[i]);
            }
            last[i] = min_s;   
        }
    }
    for(int i = 1; i <= m; i++){
        cout << last[i] << " ";
    }
    cout << endl;
    return 0;
}