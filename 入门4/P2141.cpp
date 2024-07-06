#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    unordered_set<int> numSet;
    
    // 读取输入并存入哈希集合
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        numSet.insert(nums[i]);
    }
    
    int count = 0;
    // 遍历所有数对
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int sum = nums[i] + nums[j];
            if (numSet.find(sum) != numSet.end()) {
                count++;
                numSet.erase(sum); 
            }
        }
    }
    
    cout << count << endl;
    return 0;
}
