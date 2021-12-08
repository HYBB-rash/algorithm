
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;

struct Stu {
    string name, id;
    int score;
};

vector<Stu> female, male;

bool cmp( Stu a, Stu b ) { return a.score > b.score; }

int main() {
    cin >> n;
    for ( int i = 0; i < n; i++ ) {
        string name, sex, ID;
        int score;
        cin >> name >> sex >> ID >> score;
        if ( sex == "M" )
            male.push_back( { name, ID, score } );
        else
            female.push_back( { name, ID, score } );
    }

    sort( female.begin(), female.end(), cmp );
    sort( male.rbegin(), male.rend(), cmp );

    if ( female.empty() )
        cout << "Absent" << endl;
    else
        cout << female[ 0 ].name << " " << female[ 0 ].id << endl;

    if ( male.empty() )
        cout << "Absent" << endl;
    else
        cout << male[ 0 ].name << " " << male[ 0 ].id << endl;

    if ( female.empty() || male.empty() )
        cout << "NA" << endl;
    else
        cout << female[ 0 ].score - male[ 0 ].score << endl;
    return 0;
}