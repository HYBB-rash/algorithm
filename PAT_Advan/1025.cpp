#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;

struct Stu {
    string id;
    int score, posi, rank, fin_rank;
};

vector<Stu> stus;

bool cmp( Stu a, Stu b ) {
    if ( a.score != b.score ) return a.score > b.score;
    return a.id < b.id;
}

int main() {
    cin >> n;
    for ( int i = 0; i < n; i++ ) {
        int k;
        cin >> k;
        vector<Stu> tmp;
        for ( int j = 0; j < k; j++ ) {
            string id;
            int score;
            cin >> id >> score;
            tmp.push_back( { id, score, i + 1, 0, 0 } );
        }
        sort( tmp.begin(), tmp.end(), cmp );
        tmp[ 0 ].rank = 1;
        for ( int j = 1; j < tmp.size(); j++ ) {
            tmp[ j ].rank = tmp[ j - 1 ].score == tmp[ j ].score
                                ? tmp[ j - 1 ].rank
                                : j + 1;
        }
        for ( auto &s : tmp )
            stus.push_back( s );
    }

    sort( stus.begin(), stus.end(), cmp );

    stus[ 0 ].fin_rank = 1;
    for ( int i = 1; i < stus.size(); i++ ) {
        stus[ i ].fin_rank = stus[ i - 1 ].score == stus[ i ].score
                                 ? stus[ i - 1 ].fin_rank
                                 : i + 1;
    }

    cout << stus.size() << endl;
    for ( auto &s : stus ) {
        cout << s.id << " " << s.fin_rank << " " << s.posi << " " << s.rank << endl;
    }
    return 0;
}