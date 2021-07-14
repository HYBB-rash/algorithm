
/*
 *  @File        :   Acwing3375.cpp
 *  @Time        :   2021/07/14 10:16:26
 *  @Author      :   hyong
 *  @Version     :   1.0
 *  @Contact     :   hyong_cs@outlook.com
 *  @Description :   Acwing 考研上机 排序 1
 */

#include <algorithm>
#include <cstring>
#include <functional>
#include <iostream>
#include <string>

using namespace std;

const int N = 1010;

struct stu {

    string name;
    int score;

    bool operator<(const stu &s) const { return this->score < s.score; }

    bool operator>(const stu &s) const { return this->score > s.score; }

} s[N];

int main() {

    int n, t;
    cin >> n >> t;

    for (int i = 0; i < n; i++) { cin >> s[i].name >> s[i].score; }

    t ? stable_sort(s, s + n) : stable_sort(s, s + n, greater<stu>());

    for (int i = 0; i < n; i++) cout << s[i].name << " " << s[i].score << "\n";

    return 0;
}