#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    unordered_set<int> winningNumbers;
    for (int i = 0; i < 7; ++i) {
        int num;
        cin >> num;
        winningNumbers.insert(num);
    }
    
    vector<int> prizeCounts(7, 0);  // 用于记录特等奖到六等奖的中奖张数
    
    for (int i = 0; i < n; ++i) {
        unordered_set<int> ticketNumbers;
        for (int j = 0; j < 7; ++j) {
            int num;
            cin >> num;
            ticketNumbers.insert(num);
        }
        
        // 计算匹配的号码数量
        int matchCount = 0;
        for (int num : ticketNumbers) {
            if (winningNumbers.count(num)) {
                ++matchCount;
            }
        }
        
        // 根据匹配数量更新奖项统计
        if (matchCount > 0) {
            ++prizeCounts[7 - matchCount];
        }
    }
    
    // 输出结果
    for (int count : prizeCounts) {
        cout << count << " ";
    }
    cout << endl;
    
    return 0;
}
