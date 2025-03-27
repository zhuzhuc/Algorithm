#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;
bool can(const string& pass){
    unordered_map<char, int> mp;
    bool l = false, num =false, spe = false;
    for(char ch : pass){
        mp[ch]++;
        if(isalpha(ch)) l = true;
        else if(isdigit(ch)) num = true;
        else spe = true;
        if(mp[ch] > 2) return false;
    }
    if(pass.length() < 6) return false;
    return l and num and spe;
}
bool you(const string& pass){
    bool l = false, num =false, spe = false;
    for(char ch : pass){
        if(isalpha(ch)) l = true;
        else if(isdigit(ch)) num = true;
        else spe = true;
    }
    if(pass.length() < 6) return false;
    return l and num and spe;
}
int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        string pass; cin >> pass;
        if(can(pass)) cout << 2 << endl;
        else if(you(pass)) cout << 1 << endl;
        else cout << 0 << endl;
    }

    return 0;
}