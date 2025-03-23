#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> matrix(n);
        for (int i = 0; i < n; ++i) {
            cin >> matrix[i];
        }

        // Row and column XOR arrays
        vector<int> rowXOR(n, 0);
        vector<int> colXOR(m, 0);

        // Calculate row XOR and column XOR
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                rowXOR[i] ^= (matrix[i][j] - '0');
                colXOR[j] ^= (matrix[i][j] - '0');
            }
        }

        // Count rows and columns with XOR = 1
        int rowChanges = 0, colChanges = 0;
        for (int i = 0; i < n; ++i) {
            if (rowXOR[i] == 1) rowChanges++;
        }
        for (int j = 0; j < m; ++j) {
            if (colXOR[j] == 1) colChanges++;
        }

        // The minimum number of changes needed
        int minChanges = min(rowChanges, colChanges) + abs(rowChanges - colChanges);
        cout << minChanges << endl;
    }

    return 0;
}
