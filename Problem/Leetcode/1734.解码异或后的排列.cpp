/*
 * @lc app=leetcode.cn id=1734 lang=cpp
 *
 * [1734] 解码异或后的排列
 */
#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
  public:
    vector<int> decode(vector<int> &encoded) {
        int total = 0;
        for (int i = 1; i <= encoded.size() + 1; i++)
            total ^= i;
        
        int total_without_head = 0;
        for (int i = 1; i < encoded.size(); i += 2)
            total_without_head ^= encoded[i];
        
        vector<int> res(encoded.size() + 1);
        res[0] = total ^ total_without_head;

        for (int i = 1; i <= encoded.size(); i++)
            res[i] = res[i - 1] ^ encoded[i - 1];
        
        return res;
    }
};
// @lc code=end
