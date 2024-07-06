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

/*void solve() {
    int l, m;
    cin >> l >> m;
    
    vector<bool> road(l + 1, true); 

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        for (int j = u; j <= v; ++j) {
            road[j] = false;
        }
    }
    
    int remaining_trees = 0;
    for (int i = 0; i <= l; ++i) {
        if (road[i]) {
            remaining_trees++;
        }
    }
    
    cout << remaining_trees << endl;
}
*/
int main() {
    int s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    
    vector<int> frequency(s1 + s2 + s3 + 1, 0);  // Array to store frequency of each possible sum

    // Simulate rolling the dice
    for (int i = 1; i <= s1; ++i) {
        for (int j = 1; j <= s2; ++j) {
            for (int k = 1; k <= s3; ++k) {
                int sum = i + j + k;
                frequency[sum]++;
            }
        }
    }

    // Find the most frequent sum
    int max_frequency = 0;
    int most_frequent_sum = 0;
    for (int sum = 3; sum <= s1 + s2 + s3; ++sum) {  // Possible sums range from 3 to s1+s2+s3
        if (frequency[sum] > max_frequency) {
            max_frequency = frequency[sum];
            most_frequent_sum = sum;
        }
    }

    cout << most_frequent_sum << endl;
    return 0;
}