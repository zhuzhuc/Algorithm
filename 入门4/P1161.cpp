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
void solve(){
    int n;
    cin >> n;
    unordered_set<int> lamps;
    for (int _ = 0; _ < n; ++_)
    {
        double a;
        int t;
        cin >> a >> t;
        for (int __ = 1; __ <= t; ++__)
        {
            /* code */int lamp_num = static_cast<int>(floor(__ * a));
            if (lamps.find(lamp_num) != lamps.end())
            {
                /* code */lamps.erase(lamp_num);
            }else{
                lamps.insert(lamp_num);
            }
        }
    }
    cout << *lamps.begin() << endl;


}
int main(int argc, char const *argv[])
{   

    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
