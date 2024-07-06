#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> scores(n, vector<int>(3));

    // Reading the scores for each student
    for (int i = 0; i < n; ++i) {
        cin >> scores[i][0] >> scores[i][1] >> scores[i][2];
    }

    int rivalCount = 0;

    // Comparing each pair of students to determine if they are rivals
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            bool rival = true;
            int totalScoreI = scores[i][0] + scores[i][1] + scores[i][2];
            int totalScoreJ = scores[j][0] + scores[j][1] + scores[j][2];

            // Check if each subject's score difference is within 5
            for (int k = 0; k < 3; ++k) {
                if (abs(scores[i][k] - scores[j][k]) > 5) {
                    rival = false;
                    break;
                }
            }

            // Check if the total score difference is within 10
            if (rival && abs(totalScoreI - totalScoreJ) > 10) {
                rival = false;
            }

            if (rival) {
                ++rivalCount;
            }
        }
    }

    cout << rivalCount << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
