
/**
 * *  @File        :   Acwing435.cpp
 * *  @Time        :   2021/05/04 14:43:06
 * *  @Author      :   hyong
 * *  @Version     :   1.0
 * *  @Contact     :   hyong_cs@outlook.com
 * !  @Description :   每日一题 dp
 **/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<vector<int>>> f(40, vector<vector<int>>(40, vector<int>(40, 0)));

int n, m;
int main() {

  cin >> n >> m;
  f[1][1][2] = 1, f[1][1][n] = 1;
  for (int j = 2; j <= m; j++) {
    for (int i = 1; i <= n; i++) {
      int max_app = 0;
      max_app = f[i - 1 == 0 ? n : i - 1][j - 1][i] +
                f[i + 1 > n ? 1 : i + 1][j - 1][i];
      f[i][j][i + 1 > n ? 1 : i + 1] = max_app;
      f[i][j][i - 1 == 0 ? n : i - 1] = max_app;
    }
  }
  int res = f[n][m][1] + f[2][m][1];
  cout << res;
  return 0;
}
