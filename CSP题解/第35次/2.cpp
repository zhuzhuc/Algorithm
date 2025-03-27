// int main() {
//     string s;
//     getline(cin, s); // 读取整行，包括可能的空格
//     s = s.substr(1, s.size()-2); // 去掉首尾的#
    
//     int n;
//     cin >> n;
//     cin.ignore(); // 忽略换行符
    
//     map<char, char> f; // 替换规则 f[ch1] = ch2
//     for (int i = 0; i < n; ++i) {
//         string line;
//         getline(cin, line);
//         char ch1 = line[1];
//         char ch2 = line[2];
//         f[ch1] = ch2;
//     }
    
//     // 预处理每个字符的变换周期
//     map<char, pair<int, vector<char>>> cycles;
//     for (auto& p : f) {
//         char ch = p.first;
//         vector<char> path;
//         char current = ch;
//         while (true) {
//             path.push_back(current);
//             if (f.count(current) == 0) break;
//             current = f[current];
//             // 检查是否形成环
//             for (int i = 0; i < path.size(); ++i) {
//                 if (path[i] == current) {
//                     // 找到环的起点
//                     int cycle_start = i;
//                     int cycle_len = path.size() - cycle_start;
//                     vector<char> cycle(path.begin() + cycle_start, path.end());
//                     cycles[ch] = {cycle_start, cycle};
//                     goto next_char;
//                 }
//             }
//         }
//         cycles[ch] = {0, path}; // 无环，只有路径
//         next_char:;
//     }
    
//     int m;
//     cin >> m;
//     vector<int> queries(m);
//     for (int i = 0; i < m; ++i) {
//         cin >> queries[i];
//     }
    
//     for (int k : queries) {
//         string result;
//         for (char ch : s) {
//             if (cycles.count(ch)) {
//                 auto& cycle_info = cycles[ch];
//                 int cycle_start = cycle_info.first;
//                 auto& cycle = cycle_info.second;
//                 int cycle_len = cycle.size() - cycle_start;
                
//                 if (k < cycle_start) {
//                     // 还在前导部分
//                     result += cycle[k];
//                 } else {
//                     // 进入循环部分
//                     int pos_in_cycle = (k - cycle_start) % cycle_len;
//                     result += cycle[cycle_start + pos_in_cycle];
//                 }
//             } else {
//                 // 无变换规则，保持原样
//                 result += ch;
//             }
//         }
//         cout << "#" << result << "#" << endl;
//     }
//     return 0;
// }
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<cstring>
 
using namespace std;
 
int main () {
	// 读取初始字符串，去除首尾的#号
	string s;
	getline(cin, s);
	s = s.substr(1, s.size() - 2);
	
	// 读取替换规则数目n
	int n;
	cin >> n;
	cin.ignore(); //跳过换行符
	
	//构建字符替换映射表 
	unordered_map<char, char> f_map;
	for(int i = 0; i < n; i++) {
		string line;
		getline(cin, line);
		char from = line[1]; //替换前
		char to = line[2]; //替换后
		f_map[from] = to; 
	}
	
	unordered_map<char, vector<char> > circle;
	// 构建环
	for(auto [a, b] : f_map) {
		circle[a].push_back(a);
		char c = a;
		while(f_map[c] != a) {
			c = f_map[c];
			circle[a].push_back(c);
		}
	}
	
	int count;
	cin >> count;
	for(int i = 0; i < count; i++) {
		int times;
		cin >> times;
		string result = "";
		for(int j = 0; j < s.size(); j++) {
			if(circle.count(s[j])) {
				int size = circle[s[j]].size();
				int x = times % size;
				result += circle[s[j]][x];
			}else {
				result += s[j]; // 对应题目描述中说的“未定义的视为保持不变” 
			}
		}
		cout << "#" << result << "#" << "\n";
	}
	return 0;
}