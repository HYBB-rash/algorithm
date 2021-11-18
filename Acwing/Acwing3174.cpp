#include<iostream>
#include <cstring>
#include <map>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e3 + 10;
int b[N][N];

int m, n;

PII getIndex(PII p) {
    return { p.second , n - p.first - 1};
}

int main () {
    
    cin >> n >> m;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            int tmp;
            cin >> tmp;
            auto res = getIndex({i, j});
            b[res.first][res.second] = tmp;
        }
    }
    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < n; j ++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}