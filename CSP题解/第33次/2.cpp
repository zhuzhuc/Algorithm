#include <bits/stdc++.h>
using namespace std;

string tolower(string str){
    for(auto &a : str){
        a = tolower(a);
    }
    return str;
}
int main(){
    int n,m;cin >> n >> m;
    unordered_set<string> setA, setB;
    for(int i = 0; i < n; i++){
        string s;cin >> s;
        setA.insert(tolower(s));
    }
    for(int i = 0; i < m; i++){
        string d; cin >> d;
        setB.insert(tolower(d));
    }
    unordered_set<string> inte;
    for(const auto &q : setA){
        if(setB.count(q)) inte.insert(q);
    }
    unordered_set<string> sum  = setA;
    for(const auto &w : setB){
        sum.insert(w);
    }
    cout << inte.size() << "\n" << sum.size() << endl;
    return 0;
}
