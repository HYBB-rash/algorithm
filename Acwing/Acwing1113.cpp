
/** 
 * *  @File        :   Acwing1113.cpp
 * *  @Time        :   2021/05/06 19:28:05
 * *  @Author      :   hyong
 * *  @Version     :   1.0
 * *  @Contact     :   hyong_cs@outlook.com
 * !  @Description :   1113
**/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 30;

char g[N][N];
int n, m, cnt;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

void dfs(int x, int y) {
    g[x][y] = '#';
    cnt++;
    for (int i = 0; i < 4; i++) {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || a >= n || b < 0 || b >= m || g[a][b] == '#') continue;
        dfs(a, b);
    }
}


int main() {
    while (cin >> m >> n, n || m) {
        cnt = 0;
        for (int i = 0; i < n; i++) scanf("%s", g[i]);
        int x, y, flag = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                if (g[i][j] == '@') {
                    x = i, y = j;
                    flag = 1;
                }
            if (flag) break;
        }
        dfs(x, y);
        cout << cnt << endl;
    }
    return 0;
}