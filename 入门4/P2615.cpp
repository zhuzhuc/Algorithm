#include <iostream>
#include <vector>

using namespace std;

void generateMagicSquare(int N) {
    vector<vector<int>> magicSquare(N, vector<int>(N, 0));
    
    int num = 1;
    int i = 0, j = N / 2;
    
    while (num <= N * N) {
        magicSquare[i][j] = num;
        num++;
        

        int newi = (i - 1 + N) % N;
        int newj = (j + 1) % N;
        
        if (magicSquare[newi][newj] != 0) {
            newi = (i + 1) % N;
            newj = j;
        }
        
        i = newi;
        j = newj;
    }
    

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (j != 0) cout << " ";
            cout << magicSquare[i][j];
        }
        cout << endl;
    }
}

int main() {
    int N;
    cin >> N;
    generateMagicSquare(N);
    return 0;
}
