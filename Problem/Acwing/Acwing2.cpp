#include <iostream>

using namespace std;

const int N = 1010;

int f[N];
int n, v;
int V[N], W[N];

int main () {
    cin >> n >> v;
    for (int i = 0 ; i < n; i ++) {
        cin >> V[i] >> W[i];
        
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = v; j >= V[i]; j --) {
            if (j > V[i]) f[j] = max(f[j], f[j - V[i]] + W[i]);
        }
    }
    cout << f[v];
    return 0;
}