#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> people;
    
    // 初始化所有人的编号
    for (int i = 1; i <= n; ++i) {
        people.push_back(i);
    }
    
    int index = 0; // 开始时的索引
    vector<int> result; // 记录出圈的顺序
    
    // 继续直到所有人都出圈
    while (!people.empty()) {
        // 找到下一个出圈的人的索引
        index = (index + m - 1) % people.size();
        // 记录出圈的人
        result.push_back(people[index]);
        // 将该人从圈中移除
        people.erase(people.begin() + index);
    }
    
    // 输出结果
    for (int i = 0; i < result.size(); ++i) {
        if (i > 0) cout << " ";
        cout << result[i];
    }
    cout << endl;
    
    return 0;
}
