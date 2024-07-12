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


typedef pair<int, int> Position;
typedef tuple<Position, int, Position, int> State;

const int N = 10;
const vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // 北, 东, 南, 西

struct Grid {
    vector<string> grid;
    Position cow_pos;
    Position farmer_pos;
    set<Position> obstacles;

    Grid(const vector<string>& g) : grid(g) {
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < N; ++c) {
                if (grid[r][c] == 'C') {
                    cow_pos = {r, c};
                } else if (grid[r][c] == 'F') {
                    farmer_pos = {r, c};
                } else if (grid[r][c] == '*') {
                    obstacles.insert({r, c});
                }
            }
        }
    }

    bool is_valid(Position pos) {
        return pos.first >= 0 && pos.first < N && pos.second >= 0 && pos.second < N && obstacles.find(pos) == obstacles.end();
    }

    pair<Position, int> move(Position pos, int dir) {
        Position next_pos = {pos.first + directions[dir].first, pos.second + directions[dir].second};
        if (is_valid(next_pos)) {
            return {next_pos, dir};
        } else {
            return {pos, (dir + 1) % 4};
        }
    }
};

int simulate(Grid& grid) {
    set<State> visited;
    int cow_dir = 0, farmer_dir = 0; 
    int steps = 0;

    while (true) {
        if (grid.cow_pos == grid.farmer_pos) {
            return steps;
        }

        State state = {grid.cow_pos, cow_dir, grid.farmer_pos, farmer_dir};
        if (visited.find(state) != visited.end()) {
            return 0;
        }
        visited.insert(state);

        tie(grid.cow_pos, cow_dir) = grid.move(grid.cow_pos, cow_dir);
        tie(grid.farmer_pos, farmer_dir) = grid.move(grid.farmer_pos, farmer_dir);

        ++steps;
    }
}

void solve() {
    vector<string> grid(10);
    for (int i = 0; i < 10; ++i) {
        cin >> grid[i];
    }

    Grid g(grid);
    int result = simulate(g);
    cout << result << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
