
#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    
    vector<int> school_scores(m);
    vector<int> student_scores(n);
    
    // 读取学校的预计分数线
    for (int i = 0; i < m; ++i) {
        cin >> school_scores[i];
    }
    
    // 读取学生的估分
    for (int i = 0; i < n; ++i) {
        cin >> student_scores[i];
    }
    
    // 对学校的预计分数线进行排序
    sort(school_scores.begin(), school_scores.end());
    
    long long total_dissatisfaction = 0;
    
    // 对每个学生的估分进行处理
    for (int i = 0; i < n; ++i) {
        int score = student_scores[i];
        // 使用 lower_bound 查找第一个大于等于 score 的位置
        auto it = lower_bound(school_scores.begin(), school_scores.end(), score);
        
        if (it == school_scores.end()) {
            // 如果所有学校的分数线都小于学生的估分
            total_dissatisfaction += score - school_scores.back();
        } else if (it == school_scores.begin()) {
            // 如果所有学校的分数线都大于学生的估分
            total_dissatisfaction += *it - score;
        } else {
            // 计算与相邻学校分数线的差值，取最小值
            int higher = *it;
            int lower = *(it - 1);
            total_dissatisfaction += min(abs(higher - score), abs(score - lower));
        }
    }
    
    // 输出所有学生的不满意度之和
    cout << total_dissatisfaction << endl;
    
    return 0;
}

