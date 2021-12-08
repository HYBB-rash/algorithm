
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 10;

struct Human {
    int virual, talent, total, rank;
    string ID;
} humans[ N ];

int v, h, n;

bool cmp( Human a, Human b ) {
    if ( a.rank != b.rank ) return a.rank < b.rank;
    if ( a.total != b.total ) return a.total > b.total;
    if ( a.virual != b.virual ) return a.virual > b.virual;
    return a.ID < b.ID;
}

int main() {
    cin >> n >> v >> h;

    int cnt = 0;
    for ( int i = 0; i < n; i++ ) {
        string id;
        int a, b;
        cin >> id >> a >> b;
        if ( a < v || b < v ) continue;
        if ( a >= h && b >= h ) {
            humans[ cnt++ ] = { a, b, a + b, 1, id };
        } else if ( a >= h && b < h ) {
            humans[ cnt++ ] = { a, b, a + b, 2, id };
        } else if ( a >= b ) {
            humans[ cnt++ ] = { a, b, a + b, 3, id };
        } else {
            humans[ cnt++ ] = { a, b, a + b, 4, id };
        }
    }

    sort( humans, humans + cnt, cmp );

    cout << cnt << endl;
    for ( int i = 0; i < cnt; i++ ) {
        auto h = humans[i];
        // cout << h.rank << endl;
        cout << h.ID << " " << h.virual << " " << h.talent << endl;
    }
    return 0;
}