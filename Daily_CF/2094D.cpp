#include <iostream>
#include <string>
#include <vector>
using namespace std;
// bool isValid(const string& p, const string& s) {
//     int i = 0, j = 0;
//     int n = p.size(), m = s.size();
//     if (m < n || p[0] != s[0] || m > 2 * n) return false;
//     vector<int> cc, bb;
//     int cnt = 1;
//     for (int i = 1; i < n; i++) {
//         if (p[i] != p[i - 1]) {
//             cc.push_back(cnt);
//             cnt = 1;
//         } else {
//             cnt++;
//         }
//     }
//     cc.push_back(cnt);
//     cnt = 1;
//     for (int i = 1; i < m; i++) {
//         if (s[i] != s[i - 1]) {
//             bb.push_back(cnt);
//             cnt = 1;
//         } else {
//             cnt++;
//         }
//     }
//     bb.push_back(cnt);
//     if (cc.size() != bb.size()) return false;
//     for (int i = 0; i < cc.size(); i++) {
//         if (cc[i] > bb[i] || cc[i] * 2 < bb[i]) return false;
//     }
//     return true;
// }

// void solve() {
//     string p, s;
//     cin >> p >> s;
//     cout << (isValid(p, s) ? "YES" : "NO") << endl;
// }
void solve1(){
    string p, s;
    cin >> p >> s;
    int n = p.size(), m = s.size();

    if(n > m || p[0] != s[0] || m > 2 * n){
        cout << "NO\n";
        return;
    }

    vector<int> a, b;
    int count = 1;
    for(int i = 1; i < n; i++){
        if(p[i] != p[i - 1]){
            a.push_back(count);
            count = 1;
        }else{
            count++;
        }
    }
    a.push_back(count);

    count = 1;
    for(int i = 1; i < m; i++){
        if(s[i] != s[i - 1]){
            b.push_back(count);
            count = 1;
        }else{
            count++;
        }
    }
    b.push_back(count);

    if(a.size() != b.size()){
        cout << "NO\n";
        return;
    }
    for(int i = 0; i < a.size(); i++){
        if(a[i] > b[i] || a[i] * 2 < b[i]){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
void solve2(){
    string p, s;
    cin >> p >> s;
    int n = p.size(), m = s.size();
    if(n > m || p[0] != s[0] || m > 2 * n){
        cout << "NO\n";
        return;
    }
    int i = 0; int j  = 0;
    while(i < n && j < m){
        if(p[i]!= s[j]){
            cout << "NO\n";
            return;
        }
        int count_p = 1;
        while(i + 1 < n && p[i] == p[i + 1]){
            i++;
            count_p++;
        }
        int count_s = 1;
        while(j + 1 < m && s[j] == s[j + 1]){
            j++;
            count_s++;
        }
        if(count_p > count_s || count_p * 2 < count_s){
            cout << "NO\n";
            return;
        }
        i++;
        j++;
    }
    if(i == n && j == m){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        // solve1();
        solve2();
    }
    return 0;
}