
/** 
 * *  @File        :   Acwing3502.cpp
 * *  @Time        :   2021/05/13 19:45:33
 * *  @Author      :   hyong
 * *  @Version     :   1.0
 * *  @Contact     :   hyong_cs@outlook.com
 * !  @Description :   acwing 3502
**/

#include <vector>
#include <set>
#include <iostream>

using namespace std;

vector<int> path;
int mat[10][10];
set<vector<int>> res;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int n, m, k;

void dfs(int step, int x, int y) {
    path.push_back(mat[x][y]);
    if (step == k) {
        res.insert(path);
        path.pop_back();
        return;
    }
    for (int u = 0; u < 4; u++) {
        int xx = x + dx[u], yy = y + dy[u];
        if (xx >= n || xx < 0) continue;
        if (yy >= m || yy < 0) continue;
        dfs(step + 1, xx, yy);
    }
    path.pop_back();
}

int main() {

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j ++) {
            dfs(0, i, j);
        }
    }

    cout << res.size() << endl;
    return 0;
}