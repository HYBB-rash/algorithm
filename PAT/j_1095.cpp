
/*
 *  @File        :   j_1095.cpp
 *  @Time        :   2021/07/17 10:14:29
 *  @Author      :   hyong
 *  @Version     :   1.0
 *  @Contact     :   hyong_cs@outlook.com
 *  @Description :   1095 Cars on Campus (30 分)
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

#define IN  100
#define OUT 200

const int N = 10000100;

struct rec {
    int time, status;
    bool operator<(const rec &r) const { return this->time < r.time; }
    bool operator>(const rec &r) const { return this->time > r.time; }
};

int str2int(string time) {
    time.push_back(':');
    vector<int> times;

    for (int i = 0, j = 0; i < time.size(); i++) {
        if (time[i] != ':') continue;
        int cnt = 0;
        for (int k = j; k < i; k++) cnt = cnt * 10 + (time[k] - '0');
        times.push_back(cnt);
        j = i + 1;
    }

    return times[2] * 60 + times[1] * 3600 + times[0] * 24 * 3600;
}

string int2str(int time) {
    int hh = time / 60;
    int mm = time % 60 / 60;
    int ss = time % 3600;
    return to_string(hh) + ":" + to_string(mm) + ":" + to_string(ss);
}

int str2stus(string status) {
    if (status == "in") return IN;
    if (status == "out") return OUT;
    return 0;
}

map<string, vector<rec>> table;

int cnt[N] = {}, res_cnt[N + 1] = {};

void insert(int l, int r, int k) { cnt[l] += k, cnt[r + 1] -= k; }

void refresh_cnt() {
    for (int i = 1; i <= N; i++) { res_cnt[i] = res_cnt[i - 1] + cnt[i - 1]; }
}

int main() {

    int m, n;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string ID, time, status;
        cin >> ID >> time >> status;

        int int_time = str2int(time);
        int int_status = str2stus(status);
        rec data;
        data.status = int_status, data.time = int_time;
        table[ID].push_back(data);
    }

    for (auto kv : table) {
        rec r;
        r.status = 300 - kv.second.back().status;
        kv.second.push_back(r);
        vector<rec> handle;
        for (int i = 1, j = 0; i < kv.second.size(); i++) {
            if (kv.second[i - 1].status != kv.second[i].status) {
                if (kv.second[i - 1].status == IN) {
                    handle.push_back(kv.second[i - 1]);
                } else {
                    handle.push_back(kv.second[j]);
                }
                j = i;
            }
        }
        kv.second.pop_back();
        kv.second = handle;

        for (auto val : kv.second)
            cout << kv.first << " " << val.status << " " << val.time << " "
                 << endl;

        sort(kv.second.begin(), kv.second.end());

        cout << endl;

        for (int i = 0; i < kv.second.size(); i += 2) {
            insert(kv.second[i].time, kv.second[i + 1].time, 1);
        }
        // for (auto val : kv.second)
        //     cout << kv.first << " " << val.status << " " << val.time << " "
        //          << endl;

        cout << endl;
    }

    // cout << endl;
    // for (auto kv : table) {
    //     vector<rec> datas = kv.second;
    //     for (int i = 0; i < datas.size() && i + 1 < datas.size(); i+=2) {
    //         insert(datas[i].time, datas[i + 1].time, 1);
    //         cout << datas[i].time << " " << datas[i + 1].time << endl;
    //     }
    // }

    refresh_cnt();

    // for (int i = 0; i < N; i++) cout << res_cnt[i] << " ";
    // cout << endl;

    for (int i = 0; i < m; i++) {
        string time;
        cin >> time;

        int int_time = str2int(time);
        cout << int_time + 1 << endl;
        cout << res_cnt[int_time + 1] << endl;
    }

    return 0;
}