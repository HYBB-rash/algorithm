/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 *
 * [1011] 在 D 天内送达包裹的能力
 */

// @lc code=start
class Solution {
public:
    int find(int l, int r, int target, vector<int> &f) {
        while (l < r) {
            int mid = (l + r) >> 1;
            // cout << mid << endl;
            if (f[mid] >= target) r = mid;
            else l = mid + 1;
        }
        return f[l] == target || f[l] < target ? l : l - 1;
    }
    int shipWithinDays(vector<int>& weights, int D) {
        int max_weight = 0;
        vector<int> f(weights.size() + 1);
        for (int i = 1; i <= weights.size(); i ++) {
            f[i] = f[i - 1] + weights[i - 1];
            max_weight = max(max_weight, weights[i - 1]);
        }
        // for (auto i : f) {
        //     cout << i << " ";
        // }
        // cout << endl;
        while (true) {
            int j = 0;
            for (int i = 0; i < D; i ++) {
                // for (int current = max_weight; j < weights.size() && current >= weights[j]; current -= weights[j], j ++);
                int target = f[j] + max_weight;
                j = find(0, weights.size(), target, f);
                // cout << target << " " << f[j] << endl;
                // cout << j << endl;
            }
            if (j == weights.size()) return max_weight;
            else max_weight ++;
        }
    }
};
// @lc code=end

