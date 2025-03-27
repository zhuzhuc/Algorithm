#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;
int main(){
    int n,m,t;
    cin >> n >> m >> t;
    int cur_n = n, cur_m =m;
    vector<vector<int>> oa(n, vector<int>(m));
    for(int i = 0; i < cur_n; i++)
        for(int j = 0; j < cur_m; j++)
            cin >> oa[i][j];
    while(t--){
        int op, a,b;
        cin >> op >> a >> b;
        if (op == 1)
        {
            vector<int> temp(cur_n*cur_m);
            int index = 0;
            for(int i = 0; i < cur_n; i++)
                for(int j = 0; j < cur_m; j++)
                    temp[index++] = oa[i][j];
            cur_n = a;cur_m = b;
            oa = vector<vector<int>>(cur_n, vector<int>(cur_m));
            index = 0;
            for(int i = 0; i < cur_n; i++)
                for(int j = 0; j < cur_m; j++)
                    oa[i][j] = temp[index++];
        }
        else if(op == 2){
            vector<vector<int>> new_oa(cur_m, vector<int>(cur_n));
            for(int i = 0; i < cur_n; i++)
                for(int j = 0; j < cur_m; j++)
                    new_oa[j][i] = oa[i][j];
            swap(cur_n, cur_m);
            oa = new_oa;
        }else{
            cout << oa[a][b] << endl;
        }
    }

    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;

struct Matrix {
    int rows, cols;
    vector<vector<int>> data;
    
    Matrix(int r, int c) : rows(r), cols(c), data(r, vector<int>(c)) {}
    
    void reshape(int p, int q) {
        vector<int> temp(rows * cols);
        int idx = 0;
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                temp[idx++] = data[i][j];
        
        rows = p;
        cols = q;
        data = vector<vector<int>>(p, vector<int>(q));
        
        idx = 0;
        for (int i = 0; i < p; ++i)
            for (int j = 0; j < q; ++j)
                data[i][j] = temp[idx++];
    }
    
    void transpose() {
        vector<vector<int>> new_data(cols, vector<int>(rows));
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                new_data[j][i] = data[i][j];
        swap(rows, cols);
        data = new_data;
    }
    
    int query(int i, int j) {
        return data[i][j];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, t;
    cin >> n >> m >> t;
    
    Matrix mat(n, m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> mat.data[i][j];
    
    while (t--) {
        int op, a, b;
        cin >> op >> a >> b;
        
        if (op == 1) {
            mat.reshape(a, b);
        } else if (op == 2) {
            mat.transpose();
        } else if (op == 3) {
            cout << mat.query(a, b) << "\n";
        }
    }
    
    return 0;
}
*/