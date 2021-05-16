
/**
 * *  @File        :   Acwing1540.cpp
 * *  @Time        :   2021/05/02 17:33:16
 * *  @Author      :   hyong
 * *  @Version     :   1.0
 * *  @Contact     :   hyong_cs@outlook.com
 * !  @Description :   每日一题
 **/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {

  int n, m;
  cin >> n >> m;
  vector<vector<int>> matrix(n, vector<int>(m, 0));
  unordered_map<int, int> hash;
  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> matrix[i][j];
      hash[matrix[i][j]]++;
      if (hash[matrix[i][j]] >= (n * m + 1) / 2)
        res = matrix[i][j];
    }
  }
  cout << res;
  return 0;
}