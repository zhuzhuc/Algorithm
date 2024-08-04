#pragma comment(linker, "/STACK:1024000000,1024000000")
#ifndef _GLIBCXX_NO_ASSERT
#include<cassert>
#endif
#include<cctype>
#include<cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
 
#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
//#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
 
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define ll long long
#define dou double
using namespace std;

typedef unsigned long long ull;
#define ms(s) memset(s, 0, sizeof(s))
const int inf = 0x3f3f3f3f;
#define LOCAL
 
int gcd(int a, int b){
	while(b != 0 ){
		int tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}
int lcm(int a, int b){
	return a * b / gcd(a, b);
}
 
void solve(){

    int n;
    cin >> n;
    vector<int> k(n);
    for (int i = 0; i < n; ++i)
    {
    	cin >> k[i];
    }
    int z = 1;
    for (int i = 0; i < n; ++i)
    {
    	z = lcm(z, k[i]);
    }
    int sum  = 0;
    for (int i = 0; i < n; ++i)
    {
    	sum += z / k[i];/* code */
    }
    if (sum < z)
    {
    	for (int i = 0; i < n; ++i)
    		{
    			/* code */cout << z / k[i] << " ";
    		}	/* code */
    			cout << "\n";
    }else{
    	cout << -1 << "\n";
    }
    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
     int T;cin >> T;
     while(T--){solve();}               
    
    return 0;
}
/*

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> k(n);
    for (int i = 0; i < n; ++i) {
        cin >> k[i];
    }

    // Check if we can find a valid distribution of bets
    long long total = accumulate(k.begin(), k.end(), 0LL);
    vector<long long> x(n);
    long long sum_bets = 0;
    bool possible = false;

    for (int i = 0; i < n; ++i) {
        x[i] = total - k[i];
        sum_bets += x[i];
    }

    for (int i = 0; i < n; ++i) {
        if (k[i] * x[i] > sum_bets) {
            possible = true;
            break;
        }
    }

    if (possible) {
        for (int i = 0; i < n; ++i) {
            cout << x[i] << " ";
        }
        cout << "\n";
    } else {
        cout << "-1\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}


 */