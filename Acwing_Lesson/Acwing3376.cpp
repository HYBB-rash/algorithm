
/*
 *  @File        :   Acwing3376.cpp
 *  @Time        :   2021/07/14 10:25:13
 *  @Author      :   hyong
 *  @Version     :   1.0
 *  @Contact     :   hyong_cs@outlook.com
 *  @Description :   Acwing 考研上机 排序 2
 */

#include <algorithm>
#include <cstring>
#include <functional>
#include <iostream>
#include <string>

using namespace std;

const int N = 110;

struct Student {
    int id, score;

    bool operator>(const Student &s) const {
        if (this->score != s.score) return this->score > s.score;
        return this->id < s.id;
    }

    bool operator<(const Student &s) const {
        if (this->score != s.score) return this->score < s.score;
        return this->id < s.id;
    }
} s[N];

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) { cin >> s[i].id >> s[i].score; }

    sort(s, s + n);

    for (int i = 0; i < n; i++) {
        cout << s[i].id << " " << s[i].score << "\n";
    }

    return 0;
}