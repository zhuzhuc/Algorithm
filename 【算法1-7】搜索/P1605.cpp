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

bool isLeapYear(int year) {
    if (year % 400 == 0) {
        return true;
    } else if (year % 100 == 0) {
        return false;
    } else if (year % 4 == 0) {
        return true;
    } else {
        return false;
    }
}

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true; 
    if (n % 2 == 0) return false; 
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

string multiply(string num1, int num2) {
    int carry = 0;
    for (int i = num1.size() - 1; i >= 0; --i) {
        int product = (num1[i] - '0') * num2 + carry;
        num1[i] = (product % 10) + '0';
        carry = product / 10;
    }
    while (carry) {
        num1.insert(num1.begin(), (carry % 10) + '0');
        carry /= 10;
    }
    return num1;
}

string factorial(int n) {
    string result = "1";
    for (int i = 2; i <= n; ++i) {
        result = multiply(result, i);
    }
    return result;
}

int count_digit(const string& number, char digit) {
    return count(number.begin(), number.end(), digit);
}
int N, M, T, SX, SY, FX, FY;
vector<vector<bool>> maze;  // 表示迷宫，true为障碍物
int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  // 四个方向
int paths = 0;

void dfs(int x, int y, vector<vector<bool>>& visited) {
    // 到达终点，找到一条路径
    if (x == FX && y == FY) {
        paths++;
        return;
    }

    // 标记当前格子为已访问
    visited[x][y] = true;

    // 尝试四个方向
    for (int i = 0; i < 4; i++) {
        int nx = x + directions[i][0];
        int ny = y + directions[i][1];

        // 检查边界和是否可以访问
        if (nx >= 1 && nx <= N && ny >= 1 && ny <= M && !visited[nx][ny] && !maze[nx][ny]) {
            dfs(nx, ny, visited);
        }
    }

    // 回溯
    visited[x][y] = false;
}

int main() {
    // 输入数据
    cin >> N >> M >> T;
    cin >> SX >> SY >> FX >> FY;

    maze.resize(N + 1, vector<bool>(M + 1, false));
    vector<vector<bool>> visited(N + 1, vector<bool>(M + 1, false));

    // 读取障碍物的位置
    for (int i = 0; i < T; i++) {
        int bx, by;
        cin >> bx >> by;
        maze[bx][by] = true;
    }

    // 从起点开始深度优先搜索
    dfs(SX, SY, visited);

    // 输出结果
    cout << paths << endl;

    return 0;
}
