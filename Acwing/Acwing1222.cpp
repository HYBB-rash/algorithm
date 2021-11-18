#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

char s[N];
int f[N][N];//区间 [l, r] 中所有子序列的最大长度
// TODO不会dp
int main(){
    scanf("%s", s);

    int n = strlen(s);

    for(int len = 1; len <= n; len ++){
        for(int l = 0; l + len - 1 < n; l ++){
            int r = l + len - 1;
            if(len == 1) f[l][r] = 1;
            else{
                if(s[l] == s[r]) f[l][r] = f[l + 1][r - 1] + 2;
                f[l][r] = max(f[l][r], f[l][r - 1]);
                f[l][r] = max(f[l][r], f[l + 1][r]);
            }
        }
    }

    printf("%d\n", n - f[0][n - 1]);

    return 0;
}
