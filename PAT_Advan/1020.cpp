
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

/* 典型的后序 + 中序建树 */
vector<int> inorder, postorder;
map<int, int> mapper;


struct Node {
    int val;
    Node *left, *right;
};

Node *build( int in_l, int in_r, int post_l, int post_r ) {
    if ( in_l > in_r ) return nullptr;

    Node *root  = new Node();
    root->val   = postorder[ post_r ];
    int idx     = mapper[ root->val ];
    root->left  = build( in_l, idx - 1, post_l, post_l + idx - in_l - 1 );
    root->right = build( idx + 1, in_r, post_l + idx - in_l, post_r - 1 );
    return root;
}

int main() {
    int n;
    cin >> n;

    inorder.resize( n ), postorder.resize( n );
    for ( int i = 0; i < n; i++ )
        cin >> postorder[ i ];
    for ( int i = 0; i < n; i++ ) {
        cin >> inorder[ i ];
        mapper[ inorder[ i ] ] = i;
    }

    auto root = build( 0, n - 1, 0, n - 1 );

    queue<Node *> q;
    q.push( root );
    vector<int> ans;
    while ( !q.empty() ) {
        auto node = q.front();
        q.pop();

        ans.push_back( node->val );
        if ( node->left != nullptr ) q.push( node->left );
        if ( node->right != nullptr ) q.push( node->right );
    }

    for ( int i = 0; i < ans.size(); i++ ) {
        if ( i != 0 ) cout << " ";
        cout << ans[ i ];
    }
    return 0;
}