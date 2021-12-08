#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Stu {
    string name, id;
    int score;
};

int n;
int start, e;
vector<Stu> stus;

bool cmp( Stu a, Stu b ) { return a.score > b.score; }

int main() {
    cin >> n;
    for ( int i = 0; i < n; i++ ) {
        string name, id;
        int score;
        cin >> name >> id >> score;

        stus.push_back( { name, id, score } );
    }
    sort( stus.begin(), stus.end(), cmp );
    cin >> start >> e;

    int cnt = 0;
    for ( auto &s : stus ) {

        if ( s.score <= e && s.score >= start ) {
            cout << s.name << " " << s.id << endl;
            cnt ++;
        }
    }

    if (cnt == 0) cout << "NONE" << endl;
    return 0;
}