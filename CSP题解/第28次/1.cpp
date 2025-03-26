#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>  
#include <iomanip>
using namespace std;
const int N = 100010;
double m;
int n;
int x;
int  main(){
    cin >> n >> m;
    vector<double> v(n + 1);
    for(int i = 0; i <= n; i++){
        cin >> v[i];
    }
    double toto = 0.0;
    for(int i = 0; i <= n; i++){
        double dis = pow(1 + m, i);
        toto += v[i] / dis;
        
    }
    cout << fixed << setprecision(3) << toto << endl;
    return 0;
}