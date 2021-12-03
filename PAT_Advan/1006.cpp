#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

struct User {
    PII times;
    string ID;
};

bool cmp_first( User a, User b ) { return a.times.first < b.times.first; }

bool cmp_second( User a, User b ) { return a.times.second > b.times.second; }

int main() {
    int n;
    cin >> n;

    vector<User> list;
    for ( int i = 0; i < n; i++ ) {
        User u;
        cin >> u.ID;
        int hh, mm, ss;
        scanf( "%d:%d:%d", &hh, &mm, &ss );
        u.times.first = hh * 60 * 60 + mm * 60 + ss;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        u.times.second = hh * 60 * 60 + mm * 60 + ss;
        list.push_back(u);
    }

    sort( list.begin(), list.end(), cmp_first );
    cout << list[ 0 ].ID << " ";

    sort( list.begin(), list.end(), cmp_second );
    cout << list[ 0 ].ID;

    return 0;
}