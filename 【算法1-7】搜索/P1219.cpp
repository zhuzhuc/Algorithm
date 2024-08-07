#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> solution;
int total_solutions = 0;
vector<vector<int>> all_solutions;

void solve(int row, vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2) {
    if (row == n) {
        total_solutions++;
        if (all_solutions.size() < 3) {
            all_solutions.push_back(solution);
        }
        return;
    }

    for (int col = 0; col < n; col++) {
        if (cols[col] || diag1[row - col + n - 1] || diag2[row + col]) continue;

        solution.push_back(col + 1);
        cols[col] = diag1[row - col + n - 1] = diag2[row + col] = true;

        solve(row + 1, cols, diag1, diag2);

        cols[col] = diag1[row - col + n - 1] = diag2[row + col] = false;
        solution.pop_back();
    }
}

int main() {
    cin >> n;

    vector<bool> cols(n, false);
    vector<bool> diag1(2 * n - 1, false);
    vector<bool> diag2(2 * n - 1, false);

    solve(0, cols, diag1, diag2);

    for (const auto& sol : all_solutions) {
        for (int i = 0; i < n; i++) {
            cout << sol[i];
            if (i < n - 1) cout << " ";
        }
        cout << endl;
    }

    cout << total_solutions << endl;

    return 0;
}
