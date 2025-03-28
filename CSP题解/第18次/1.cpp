#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;
const int N = 101000;




int isskip(int x){
    if(x % 7 == 0) return true;
    string s = to_string(x);
    for(char c : s){
        if(c == '7') return true;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;int count[4] = {0};
    cin >> n;
    int toto = 0;
    for(int i = 1; toto < n; i++){
        int p = (i - 1) % 4;
        if(isskip(i)){
            count[p]++;
        }
        else{
            // count[p]++;
            toto++;
        }
    }

    for(int i = 0; i < 4; i++){
        cout << count[i] << " ";
    }
    return 0;
}