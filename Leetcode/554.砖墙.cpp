/*
 * @lc app=leetcode.cn id=554 lang=cpp
 *
 * [554] 砖墙
 */

// @lc code=start

class Solution {
public:
  int leastBricks(vector<vector<int>> &wall) {
    unordered_map<int, int> record;
    for (auto line : wall) {
      for (int i = 0, s = 0; i < line.size() - 1; i++) {
        s += line[i];
        record[s]++;
      }
    }
    int res = 0;
    for (auto line : record) {
      res = max(line.second, res);
    }
    return wall.size() - res;
  }
};
// @lc code=end
