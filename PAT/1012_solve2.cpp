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

struct Student{
	string id;int C,M,E,A;
}; 

bool cmpC(const Student& a, const Student& b){return a.C > b.C;}
bool cmpM(const Student& a, const Student& b){return a.M > b.M;}
bool cmpE(const Student& a, const Student& b){return a.E > b.E;}
bool cmpA(const Student& a, const Student& b){return a.A > b.A;}
void solve(){
    int n,m;
    cin >> n >> m;
    vector<Student> s(n);
    unordered_map<string, int> index;
    
    for(int i = 0; i < n; i++){
        cin >> s[i].id >> s[i].C >> s[i].M >> s[i].E;
        s[i].A = (s[i].C + s[i].M + s[i].E)/3;
        index[s[i].id] = i;
    }
    
    vector<vector<int>> ranks(n, vector<int>(4, 0));
    
    sort(s.begin(), s.end(), cmpA);
    int rank = 1;
    for(int i = 0; i < n; i++){
        if(i > 0 && s[i].A == s[i-1].A){
            ranks[index[s[i].id]][0] = ranks[index[s[i-1].id]][0];
        }else{
            ranks[index[s[i].id]][0] = rank;
        }
        cout << "-----------------------------"<< endl;
        cout << "DEBUG: Student " << s[i].id << " A_rank = " << ranks[index[s[i].id]][0] << endl;
        rank++;
    }
    
    sort(s.begin(), s.end(), cmpC);
    rank = 1;
    for(int i = 0; i < n; i++){
        if(i > 0 && s[i].C == s[i-1].C){
            ranks[index[s[i].id]][1] = ranks[index[s[i-1].id]][1];
        }else{
            ranks[index[s[i].id]][1] = rank;
        }
        cout << "-----------------------------"<< endl;
        cout << "DEBUG: Student " << s[i].id << " C_rank = " << ranks[index[s[i].id]][0] << endl;
        rank++;
    }
    
    sort(s.begin(), s.end(), cmpM);
    rank = 1;
    for(int i = 0; i < n; i++){
        if(i > 0 && s[i].M == s[i-1].M){
            ranks[index[s[i].id]][2] = ranks[index[s[i-1].id]][2];
        }else{
            ranks[index[s[i].id]][2] = rank;
        }
        cout << "-----------------------------"<< endl;
        cout << "DEBUG: Student " << s[i].id << " M_rank = " << ranks[index[s[i].id]][0] << endl;
        rank++;
    }
    
    sort(s.begin(), s.end(), cmpE);
    rank = 1;
    for(int i = 0; i < n; i++){
        if(i > 0 && s[i].E == s[i-1].E){
            ranks[index[s[i].id]][3] = ranks[index[s[i-1].id]][3];
        }else{
            ranks[index[s[i].id]][3] = rank;
        }
        cout << "-----------------------------"<< endl;
        cout << "DEBUG: Student " << s[i].id << " E_rank = " << ranks[index[s[i].id]][0] << endl;
        rank++;
    }
    char su[4] = {'A', 'C', 'M', 'E'};
    for(int i = 0; i < m; i++){
        string ID;
        cin >> ID;
        if(!index.count(ID)){
            cout << "N/A" << endl;
        }else{
            int idx = index[ID];
            int b_r = n + 1;
            int b_s = -1;
            
            for(int j = 0; j < 4; j++){
                if(ranks[idx][j] < b_r){
                    b_r = ranks[idx][j];
                    b_s = j;
                }
            }
            cout << b_r << " " << su[b_s] << endl;
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
                    
    solve();
    return 0;
}