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
 
 
 

const int MAXN = 12;

int len;
char dat[20005];
char res[20005];
int  pos;

void input_data(){
	memset(res, 0, sizeof(res));
	cin >> dat;
	return;
}
void output_data(){
	cout << res;
	return;
}
void dfs(int low, int high){
    if(low >= high){
		return;
	}
	
	if(dat[low] == '[' && dat[high-1] == ']'){
		dfs(low+1, high-1);
		return;
	}
	int lft = 0;
	int rit = 0;
	 
	
	int beg1 = low; 
	int end1 = high;
	int beg2 = low; 
	int end2 = high;
	

	int times = 1;
	if(dat[low] >= '0' && dat[low] <= '9'){
		times = 0;
		for(int i = low; ; i++){
			if(dat[i] >= '0' && dat[i] <= '9'){
				times = times*10+dat[i]-'0';
			}else{
				beg1 = i;
				break;
			}
		}
	}
	for(int i = beg1; i < high; i++){
		 
		if(lft == 0 && i == high-1){
		    for(int j = 0; j < times; j++){
 		        for(int k = beg1; k < high; k++){
 		        	res[pos++] = dat[k];
				 }
			}
            break;
		}
		
	
		if(lft == 0 && dat[i] == '['){
			end1 = i;
			beg2 = i;
		}
		if(dat[i] == '['){
			lft++;
		} 
		if(dat[i] == ']'){
			rit++;
		}
		
		
		if(lft != 0 && rit != 0 && lft == rit){
			end2 = i+1;
			for(int j = 0; j < times; j++){
				dfs(beg1, end1);
			    dfs(beg2, end2);
				dfs(end2, high);
			}
			break;
		}
	}
	return;
}

void process_data(){
	len = strlen(dat);
	pos = 0;
	dfs(0, len);
	res[pos] = '\0';
	return;
}

int main(){
    input_data();
    process_data();
    output_data();
    
	return 0;
}