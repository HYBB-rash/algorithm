
/**
 * *  @File        :   Acwing3489.cpp
 * *  @Time        :   2021/05/15 19:28:57
 * *  @Author      :   hyong
 * *  @Version     :   1.0
 * *  @Contact     :   hyong_cs@outlook.com
 * !  @Description :   acwing 3489
 **/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, int> month{
    {"January", 1},   {"February", 2}, {"March", 3},     {"April", 4},
    {"May", 5},       {"June", 6},     {"July", 7},      {"August", 8},
    {"September", 9}, {"October", 10}, {"November", 11}, {"December", 12}};

unordered_map<int, string> week_day{
    {1, "Monday"}, {2, "Tuesday"},  {3, "Wednesday"}, {4, "Thursday"},
    {5, "Friday"}, {6, "Saturday"}, {0, "Sunday"}};

int calWeek(int y, int m, int d) {
    if (m == 1 || m == 2) m += 12, y --;
    return (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400 + 1) %
           7;
}

int main() {
    int d, y;
    string m;
    while (cin >> d >> m >> y) {
        cout << week_day[calWeek(y, month[m], d)] << endl;
    }
    return 0;
}