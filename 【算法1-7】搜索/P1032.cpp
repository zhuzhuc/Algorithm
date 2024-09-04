
#include <iostream>
#include <queue>
#include <map>
#include <string>

using namespace std;

struct Node {
    string data;
    int step;
    Node(string _data, int _step) : data(_data), step(_step) {}
    Node() {}
};

string a, b;
queue<Node> q;
string change[10]; // 变换后的字符串
string diff[10];   // 需要变换的字符串
int nxt[10][10000]; // KMP的next数组
map<string, bool> mp; // 用于判重，避免重复搜索

// 计算KMP算法的next数组
void get_next(int x) {
    int j = 0;
    for (int i = 2; i < diff[x].length(); i++) {
        while (j && diff[x][i] != diff[x][j + 1]) j = nxt[x][j];
        if (diff[x][j + 1] == diff[x][i]) j++;
        nxt[x][i] = j;
    }
}

// 
void KMP(string a, int x, int step) {
    string z = a;
    a = " " + a; 
    int j = 0;
    for (int i = 1; i < a.length(); i++) {
        while (j > 0 && diff[x][j + 1] != a[i]) j = nxt[x][j];
        if (diff[x][j + 1] == a[i]) j++;
        if (j == diff[x].length() - 1) { // 找到匹配
            int t = i - diff[x].length() + 1; 
            string tmp = z.substr(0, t) + change[x] + z.substr(t + diff[x].length() - 1); // 修改字符串
            q.push(Node(tmp, step + 1));
            j = nxt[x][j]; // 继续寻找
        }
    }
}

int main() {
    cin >> a >> b;
    string t1, t2;
    int cn = 0;
    while (cin >> t1 >> t2) {
        change[++cn] = t2;
        diff[cn] = " " + t1; 
        get_next(cn);
    }
    q.push(Node(a, 0));
    while (!q.empty()) {
        Node now = q.front();
        q.pop();
        string x = now.data;
        if (mp[x]) continue; 
        mp[x] = true; // 标记
        if (now.step > 10) {
            cout << "NO ANSWER!" << endl;
            return 0;
        }
        if (x == b) { 
            cout << now.step << endl;
            return 0;
        }
        for (int i = 1; i <= cn; i++) { // 枚举所有模式串，匹配文本串
            KMP(x, i, now.step);
        }
    }
    cout << "NO ANSWER!" << endl; // 无解
    return 0;
}

