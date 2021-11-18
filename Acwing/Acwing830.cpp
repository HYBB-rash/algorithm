
/** 
 * *  @File        :   Acwing830.cpp
 * *  @Time        :   2021/05/18 14:20:41
 * *  @Author      :   hyong
 * *  @Version     :   1.0
 * *  @Contact     :   hyong_cs@outlook.com
 * !  @Description :   acwing830
**/

#include <cstdio>

using namespace std;

const int N = 100100;
int stk[N], idx = 0;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        while (idx && stk[idx] >= x) idx--;
        if (idx) printf("%d ", stk[idx]);
        else
            printf("-1 ");
        stk[++idx] = x;
    }
    return 0;
}