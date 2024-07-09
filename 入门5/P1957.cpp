#include <bits/stdc++.h>
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

#define ll long long
#define ff first
#define ss string
#define pb push_back
#define eb emplace_back

const int maxn = 2e5 + 2;
const int maxm = 62;


void solve() {
    int i;
    cin >> i;
    char operation = ' ';
    for (int _ = 0;_ < i; ++_)
    {
   		ss in;
   		cin >> in;
   		int num1, num2;
   		if (in == "a" or in == "b" or in == "c")
   		{
   			operation = in[0];
   			cin >> num1 >> num2;
   		}else{
   			num1 = stoi(in);
   			cin >> num2;
   		}
   		int res;
   		ss opSymbol;
   		switch(operation){
   		case 'a' :
   			res = num1 + num2;
   			opSymbol = "+";
   			break;
   		case 'b' :
   			res = num1 - num2;
   			opSymbol = "-";
   			break;
   		case 'c' :
   			res = num1 * num2;
   			opSymbol = "*";
   			break;
   		}
   		ss equation = to_string(num1) + opSymbol + to_string(num2) + "=" + to_string(res);
   		cout << equation << "\n";
   		cout << equation.size() << "\n";
    }
    
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}