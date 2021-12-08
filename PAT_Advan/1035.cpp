#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<pair<string, string>> ans;

int main() {

    int n;
    cin >> n;

    for ( int i = 0; i < n; i++ ) {
        string username, password;
        cin >> username >> password;

        int cnt = 0;
        for ( auto &c : password ) {
            char tmp = c;
            if ( c == '1' ) c = '@';
            if ( c == '0' ) c = '%';
            if ( c == 'l' ) c = 'L';
            if ( c == 'O' ) c = 'o';
            if ( tmp != c ) cnt++;
        }
        if ( cnt != 0 ) ans.push_back( { username, password } );
    }

    if ( ans.size() != 0 ) {
        cout << ans.size() << endl;
        for ( auto &i : ans ) {
            cout << i.first << " " << i.second << endl;
        }
    } else {
        if ( n == 1 )
            cout << "There is 1 account and no account is modified" << endl;
        else
            cout << "There are " << n << " accounts and no account is modified"
                 << endl;
    }
    return 0;
}