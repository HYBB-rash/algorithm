
/** 
 * *  @File        :   Acwing1341.cpp
 * *  @Time        :   2021/05/11 16:58:06
 * *  @Author      :   hyong
 * *  @Version     :   1.0
 * *  @Contact     :   hyong_cs@outlook.com
 * !  @Description :   acwing 1341
**/

#include <iostream>

using namespace std;

int day_not_run[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int day_run[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int res[8];

bool is_run(int year) {
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    if (year % 4 == 0) return true;
    return false;
}

int main() {
    int n = 0, day = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int year = 1900 + i;
        int *calen = is_run(year) ? day_run : day_not_run;
        for (int j = 1; j <= 12; j++) {
            int tmp_day = day + 12;
            int xq = tmp_day % 7;
            res[xq]++;
            day += calen[j];
        }
    }
    
    for (int i = 5; i < 5 + 7; i++) cout << res[i % 7] << " ";
    return 0;
}