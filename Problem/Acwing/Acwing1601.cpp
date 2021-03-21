#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e3 + 10;

vector<vector<int>> lens(N, vector<int>(N, 0x3f3f3f3f)), times(N, vector<int>(N, 0x3f3f3f3f));
int dist[N];
bool st[N];
int s, d;

vector<vector<int>> pre_time(N), pre_lenth(N);

void dijkstra_len(int n) {

    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    dist[s] = 0;

    for (int i = 0; i < n; i ++) {
        int t = -1;
        for (int j = 0; j < n; j ++) {
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        }

        for (int j = 0; j < n; j ++) {
            if (dist[j] > dist[t] + lens[t][j]){
                dist[j] = dist[t] + lens[t][j];
                pre_lenth[j].clear();
                pre_lenth[j].push_back(t);
            } else if (dist[j] == dist[t] + lens[t][j]) {
                pre_lenth[j].push_back(t);
            }
        }
        st[t] = true;
    }
}

vector<int> ans_len, tmp_len;
int min_time = 0x3f3f3f3f;

void dfs_len(int idx, int time) {
    tmp_len.push_back(idx);
    if (pre_lenth[idx].empty()) {
        if (min_time > time) {
            min_time = time;
            ans_len = tmp_len;
            tmp_len.pop_back();
        }
        return;
    }
    for (auto i : pre_lenth[idx]) {
        dfs_len(i, time + times[i][idx]);
    }
    tmp_len.pop_back();
}

void dijkstra_time(int n) {

    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    dist[s] = 0;

    for (int i = 0; i < n; i ++) {
        int t = -1;
        for (int j = 0; j < n; j ++) {
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        }

        for (int j = 0; j < n; j ++) {
            if (dist[j] > dist[t] + times[t][j]) {
                dist[j] = dist[t] + times[t][j];
                pre_time[j].clear();
                pre_time[j].push_back(t);
            } else if (dist[j] == dist[t] + times[t][j]) {
                pre_time[j].push_back(t);
            }
        }
        st[t] = true;
    }
}

vector<int> ans_time, tmp_time;
int min_step = 0x3f3f3f3f;
void dfs_time(int idx, int steps) {
    tmp_time.push_back(idx);
    if (pre_time[idx].empty()) {
        if (min_step > steps) {
            min_step = steps;
            ans_time = tmp_time;
            tmp_time.pop_back();
        }
        return ;
    }
    for (auto i : pre_time[idx]) {
        dfs_time(i, steps + 1);
    }
    tmp_time.pop_back();
}

void printAns(vector<int> ans) {
    for (int i = ans.size() - 1; i >= 0; i --) {
        cout << ans[i];
        if (i != 0) cout << " -> ";
    }
    cout << endl;
}

int main () {

    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i ++) {
        int start, end, type, len, time;
        cin >> start >> end >> type >> len >> time;
        lens[start][end] = len, times[start][end] = time;
        if (type == 0) lens[end][start] = len, times[end][start] = time;
    }
    cin >> s >> d;
    int w_len , w_time;
    dijkstra_len(n), w_len = dist[d];
    dijkstra_time(n), w_time = dist[d];
    dfs_len(d, 0), dfs_time(d, 1);
    if (ans_len == ans_time) {
        cout << "Distance = " << w_len << "; " << "Time = " << w_time << ": ";
        printAns(ans_len);
    } else {
        cout << "Distance = " << w_len << ": ";
        printAns(ans_len);
        cout << "Time = " << w_time << ": ";
        printAns(ans_time);
    }
    return 0;
}