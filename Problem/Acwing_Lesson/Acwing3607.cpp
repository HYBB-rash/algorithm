
/*
 *  @File        :   Acwing3607.cpp
 *  @Time        :   2021/07/14 17:13:58
 *  @Author      :   hyong
 *  @Version     :   1.0
 *  @Contact     :   hyong_cs@outlook.com
 *  @Description :   Acwing 考研上机 日期 1
 */

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int is_leap(int year) { return year % 4 == 0 && year % 100 || year % 400 == 0; }

int get_day(int y, int m) {
    if (m == 2) return months[m] + is_leap(y);
    return months[m];
}

int main() {

    int y, s;
    while (cin >> y >> s) {
        int m = 1, d = 1;
        while (--s) {
            d++;
            if (d > get_day(y, m)) {
                d = 1;
                m++;
            }
            if (m > 12) {
                m = 1;
                y++;
            }
        }
        printf("%04d-%02d-%02d\n", y, m, d);
    }
    return 0;
}