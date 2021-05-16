/*
 * @lc app=leetcode.cn id=1473 lang=cpp
 *
 * [1473] 粉刷房子 III
 */
#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> f(110, vector<vector<int>>(110, vector<int>(25, 0x3f3f3f3f)));
        if (houses[0] == 0) {
            for (int i = 0; i < n; i ++) {
                f[1][1][i + 1] = cost[0][i];
            }
        } else {
            f[1][1][houses[0]] = 0;
        }
        for (int i = 2; i <= m; i ++) {
            for (int j = 1; j <= target; j ++) {
                if (houses[i - 1] == 0)
                    for (int k = 1; k <= n; k ++) {
                        int min_cost = 0x3f3f3f3f;
                        int house_index = i - 1, part_index = j - 1, color_index = k - 1;
                        int color_cost = cost[house_index][color_index];
                        for (int u = 1; u <= n; u++) {
                            if (u == k)
                                min_cost = min(min_cost, f[i - 1][j][u]);
                            else
                                min_cost = min(min_cost, f[i - 1][j - 1][u]);
                        }
                        f[i][j][k] = min(f[i][j][k], min_cost + color_cost);
                    }
                else {
                    int k = houses[i - 1];
                    int min_cost = 0x3f3f3f3f;
                    for (int u = 1; u <= n; u++) {
                            if (u == k)
                                min_cost = min(min_cost, f[i - 1][j][u]);
                            else
                                min_cost = min(min_cost, f[i - 1][j - 1][u]);
                    }
                    f[i][j][k] = min_cost;
                }
            }
        }
        int res = 0x3f3f3f3f;
        for (int i = 1; i <= n; i ++) res = min(f[m][target][i], res);
        if (res >= 0x3f3f3f3f) return -1;
        return res;
    }
};
// @lc code=end

