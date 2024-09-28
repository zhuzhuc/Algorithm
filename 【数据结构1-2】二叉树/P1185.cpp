
#include <bits/stdc++.h>
using namespace std;

// 预计算每层的节点数
int node_count[12] = {0, 1, 2, 5, 11, 23, 47, 95, 191, 383, 767, 1535}; 
char pic[805][1605]; // 行数最大为767，列数最大为2*767+1=1535
bool tree[1050];
int m, n;

// 函数声明
void draw(int, int, int, int);

void draw_left(int p, int n, int x, int y) {
    int i = x, j = y, tmp = node_count[n];
    while (tmp--) {
        i++, j--;
        pic[i][j] = '/';
    }
    i++, j--;
    pic[i][j] = 'o';
    draw(p, n - 1, i, j); 
}

void draw_right(int p, int n, int x, int y) {
    int i = x, j = y, tmp = node_count[n];
    while (tmp--) {
        i++, j++;
        pic[i][j] = '\\';
    }
    i++, j++;
    pic[i][j] = 'o';
    draw(p, n - 1, i, j);
}

void draw(int p, int n, int x, int y) {
    if (n == 0) return;
    if (tree[p << 1]) { // 如果有左子树
        draw_left(p << 1, n, x, y); // 画左子树
    }
    if (tree[(p << 1) | 1]) { // 如果有右子树
        draw_right((p << 1) | 1, n, x, y); // 画右子树
    }
}

int main() {
    memset(pic, ' ', sizeof(pic)); // 全赋值为空格
    scanf("%d%d", &m, &n);
    for (int i = 1; i < (1 << m); i++) { // 层数为m的满二叉树共有2^m-1个结点
        tree[i] = true;
    }
    while (n--) {
        int i, j; 
        scanf("%d%d", &i, &j); 
        int tmp = (1 << (i - 1)) - 1; // 满二叉树前i-1层共有2^(i-1)-1个结点
        tmp += j; // 第j个 
        tree[tmp] = false; // 删去子树 
    }
    pic[1][node_count[m] + 1] = 'o'; // 根结点 
    draw(1, m - 1, 1, node_count[m] + 1); // 画图 
    for (int i = 1; i <= node_count[m] + 1; i++) {
        for (int j = 1; j <= node_count[m + 1] + 1; j++) {
            putchar(pic[i][j]);
        } 
        putchar('\n');
    } 
    return 0;
}

