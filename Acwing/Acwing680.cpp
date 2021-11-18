/** 
 * *  @File        :   Acwing680.cpp
 * *  @Time        :   2021/04/26 19:42:47
 * *  @Author      :   hyong
 * *  @Version     :   1.0
 * *  @Contact     :   hyong_cs@outlook.com
 * !  @Description :   每日一题
**/
#include <iostream>
#include <cstring>
#include <algorithm>

const int N = 100010;
const double eps = 1e-4;

int n, m;
double l[N];

bool check(double mid)
{
    int cnt = 0;
    for (int i = 0; i < n; i ++ )
        cnt += l[i] / mid;
    return cnt >= m;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i ++ ) scanf("%lf", &l[i]);

    double l = 0, r = 1e9;
    while (r - l > eps)
    {
        double mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }

    printf("%.2lf\n", r);
    return 0;
}