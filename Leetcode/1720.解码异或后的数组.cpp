/*
 * @lc app=leetcode.cn id=1720 lang=cpp
 *
 * [1720] 解码异或后的数组
 */

// @lc code=start
class Solution {
public:
  vector<int> decode(vector<int> &encoded, int first) {
    vector<int> decoded(encoded.size() + 1);
    decoded[0] = first;
    int cnt = 1;
    for (auto num : encoded) {
      decoded[cnt] = decoded[cnt - 1] ^ num;
      cnt ++;
    }
    return decoded;
  }
};
// @lc code=end

