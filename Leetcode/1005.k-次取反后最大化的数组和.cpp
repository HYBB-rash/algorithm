/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
  public:
    int largestSumAfterKNegations( vector<int> &nums, int k ) {
        priority_queue<int, vector<int>, greater<int>> heap;
        for ( int &num : nums ) {
            heap.push(num);
        }
        while ( k-- ) {
            int num = heap.top();
            heap.pop();
            heap.push(-num);
        }
        int sum = 0;
        while ( !heap.empty() ) {
            sum += heap.top();
            heap.pop();
        }
        return sum;
    }
};
// @lc code=end
