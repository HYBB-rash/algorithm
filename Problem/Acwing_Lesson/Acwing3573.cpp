
/*
 *  @File        :   Acwing3573.cpp
 *  @Time        :   2021/07/14 17:28:56
 *  @Author      :   hyong
 *  @Version     :   1.0
 *  @Contact     :   hyong_cs@outlook.com
 *  @Description :   Acwing 上机考研 日期 2
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int is_leap(int year) { return year % 4 == 0 && year % 100 || year % 400 == 0; }

int get_days(int y, int m) {
    if (m == 2) return months[m] + is_leap(y);
    return months[m];
}

int get_year_days(int y, int m) {
    if (m <= 2) return 365 + is_leap(y);
    return 365 + is_leap(y + 1);
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int y, m, d, s;
        cin >> y >> m >> d >> s;

        if (m == 2 && d == 29) { d--, s++; }

        for (int day = get_year_days(y, m); s >= day;
             day = get_year_days(++y, m))
            s -= day;

        while (s--) {
            if (++d > get_days(y, m)) { d = 1, m++; }
            if (m > 12) { y++, m = 1; }
        }

        printf("%04d-%02d-%02d\n", y, m, d);
    }

    return 0;
}