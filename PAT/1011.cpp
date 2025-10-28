#include <bits/stdc++.h>
using namespace std;
int main(){
    double res = 1;
    for(int i = 0; i < 3; i++){
        double a,b,c;
        cin >> a >> b >> c;
        if(a>b&&a>c){
            cout << "W ";
            res *= a;
        }else if(b>a&&b>c){
            cout << "T ";
            res *= b;
        }else{
            cout << "L ";
            res *= c;
        }    
    }

    cout << fixed << setprecision(2) << res*1.3 - 2;
    return 0;
}