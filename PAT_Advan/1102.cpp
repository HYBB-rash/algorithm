// 经典的 homebrew 作者被 diss 的二叉树反转
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
};

const int N = 100010;
bool st[ N ];

void invert( Node *root ) {
    if ( root == nullptr ) return;
    invert( root->left ), invert( root->right );
    Node *tmp   = root->left;
    root->left  = root->right;
    root->right = tmp;
}

vector<int> inorder;
void dfs( Node *root ) {
    if ( root == nullptr ) return;
    dfs( root->left );
    inorder.push_back( root->val );
    dfs( root->right );
}

int main() {
    int n;
    cin >> n;
    vector<Node *> nodes( n );
    for ( int i = 0; i < n; i++ ) {
        nodes[ i ]      = new Node();
        nodes[ i ]->val = i;
    }
    for ( int i = 0; i < n; i++ ) {
        string a, b;
        cin >> a >> b;
        if ( a != "-" )
            nodes[ i ]->left = nodes[ stoi( a ) ], st[ stoi( a ) ] = true;
        if ( b != "-" )
            nodes[ i ]->right = nodes[ stoi( b ) ], st[ stoi( b ) ] = true;
    }
    int root = -1;
    for ( int i = 0; i < n; i++ ) {
        if ( !st[ i ] ) {
            root = i;
            break;
        }
    }

    Node *r = nodes[ root ];

    invert( r );

    queue<Node *> q;
    q.push( r );
    vector<int> h_ans;
    while ( q.size() ) {
        auto t = q.front();
        q.pop();
        h_ans.push_back( t->val );
        if ( t->left != nullptr ) q.push( t->left );
        if ( t->right != nullptr ) q.push( t->right );
    }
    cout << h_ans[ 0 ];
    for ( int i = 1; i < h_ans.size(); i++ )
        cout << " " << h_ans[ i ];
    cout << endl;

    dfs( r );

    cout << inorder[ 0 ];
    for ( int i = 1; i < inorder.size(); i++ )
        cout << " " << inorder[ i ];

    return 0;
}