#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

typedef long long LL;


const int N  = 1010;
int n,m;
struct point{
    long long x,y;
    char z;
}q[N];

int get(int a, int b, int c, char z){
    int s = 0;
    for(int i = 0; i < n; i++){
        if(q[i].z == z){
            if(a + b * q[i].x + c * q[i].y >0){
               s |= 1; 
            } 
            else s |= 2;
        }
    }
    return s;
}
bool check(int a, int b, int c){
    int s1 = get(a, b, c, 'A');
    int s2 = get(a, b, c, 'B');
    if(s1 == 3 || s2 == 3) return false;
    if(s1 & s2) return false;
    return true;
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> q[i].x >> q[i].y >> q[i].z;
    }
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        if(check(a,b,c)) puts("Yes");
        else puts("No");
    }
    
    return 0;
}