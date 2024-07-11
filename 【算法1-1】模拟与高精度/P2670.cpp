#include <iostream>
#include <vector>

using namespace std;


const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<string> grid(n);
    vector<string> result(n, string(m, '0')); 

    
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '*') {
                result[i][j] = '*';
            } else {
                int mineCount = 0;
                
                for (int k = 0; k < 8; ++k) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == '*') {
                        mineCount++;
                    }
                }
                result[i][j] = mineCount + '0';
            }
        }
    }


    for (int i = 0; i < n; ++i) {
        cout << result[i] << endl;
    }

    return 0;
}
