#include <bits/stdc++.h>

// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back

const int maxn = 2e5 + 2;
const int maxm = 62;

void printBigNumber(const vector<int>& num) {
    int start = num.size() - 1;
    while (start >= 0 && num[start] == 0) {
        --start;
    }
    if (start == -1) {
        cout << 0;
    } else {
        for (int i = start; i >= 0; --i) {
            cout << num[i];
        }
    }
    cout << endl;
}

void addBigNumbers(vector<int>& result, const vector<int>& num) {
    int carry = 0;
    for (size_t i = 0; i < num.size() || carry; ++i) {
        if (i == result.size()) {
            result.push_back(0);
        }
        result[i] += carry + (i < num.size() ? num[i] : 0);
        carry = result[i] / 10;
        result[i] %= 10;
    }
}
vector<int> multiplyBigNumbers(const vector<int>& num, int x) {
    vector<int> result(num.size(), 0);
    int carry = 0;
    for (size_t i = 0; i < num.size() || carry; ++i) {
        if (i == result.size()) {
            result.push_back(0);
        }
        long long current = result[i] + carry + (i < num.size() ? num[i] * 1LL * x : 0);
        result[i] = current % 10;
        carry = current / 10;
    }
    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }
    return result;
}



int main() {
   
    int n,i,j,wei=0,weii,where;
    scanf("%d",&n);
    

    wei=2;
    if(n==0)return 0;

    
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            weii=0;
            while(pow(10,weii)<=n*(i-1)+j)weii++;
            while(weii<wei){
                printf("0");
                weii++;
            }
            printf("%d",n*(i-1)+j);
        }
        printf("\n");
    }
    
    printf("\n");
    where=1;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            weii=0;
            while(pow(10,weii)<=where)weii++;
            if(n-j<i){
                while(weii<wei){
                    printf("0");
                    weii++;
                }
                printf("%d",where);
                where++;
            }
            else{
                weii=0;
                while(weii<wei){
                    printf(" ");
                    weii++;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
