#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int A, B, C;
    cin >> A >> B >> C;

    vector<int> nums = {A, B, C};
    sort(nums.begin(), nums.end());

    string order;
    cin >> order;

    unordered_map<char, int> mapping;
    mapping['A'] = nums[0];
    mapping['B'] = nums[1];
    mapping['C'] = nums[2];

    for (char c : order) {
        cout << mapping[c] << " ";
    }
    cout << endl;

    return 0;
}