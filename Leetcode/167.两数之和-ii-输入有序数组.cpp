/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
  public:
    int bs(int l, int r, int target, vector<int> &numbers) {
        while (l < r) {
            int mid = (l + r) >> 1;
            if (numbers[mid] < target)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
    vector<int> twoSum(vector<int> &numbers, int target) {
        for (int i = 0; i < numbers.size(); i++) {
            int ano_tar = target - numbers[i];
            int ano_idx = bs(i + 1, numbers.size() - 1, ano_tar, numbers);
            if (ano_tar == numbers[ano_idx])
                return vector<int>({i + 1, ano_idx + 1});
        }
        return vector<int>();
    }
};
// @lc code=end
