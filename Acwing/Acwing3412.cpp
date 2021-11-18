#include <iostream>
#include <unordered_map>
using namespace std;
typedef pair<int, int> PII;
typedef pair<PII, PII> PPP;
int n, L, r, t;
int pre_sum[1010][1010], raw[1010][1010];

PPP getIndex(int x, int y) {
    int x1 = x - r < 0 ? 0 : x - r, y1 = y - r < 0 ? 0 : y - r;
    int x2 = x + r >= n ? n - 1 : x + r, y2 = y + r >= n ? n - 1 : y + r;
    return {{x1, y1}, {x2 + 1, y2 + 1}};
}

int main () {
    cin >> n >> L >> r >> t;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++ ){
            cin >> raw[i][j];
            pre_sum[i + 1][j + 1] = raw[i][j] + pre_sum[i + 1][j] + pre_sum[i][j + 1] - pre_sum[i][j];
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            auto index = getIndex(i, j);
            auto start = index.first, end = index.second;
            int total = (end.first - start.first) * (end.second - start.second);
            // cout << total << " ";
            int sum_degree = pre_sum[end.first][end.second] - pre_sum[end.first][start.second] - pre_sum[start.first][end.second] + pre_sum[start.first][start.second];
            // cout << sum_degree << " ";
            double avg_degree = 1.0 * sum_degree / total;
            if (avg_degree <= t) cnt ++;
        }
        // cout << endl;
    }
    cout << cnt;
    return 0;
}