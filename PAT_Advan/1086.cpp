
#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <vector>

using namespace std;

vector<int> inorder, preorder;
map<int, int> mapper;

struct Node {
    int val;
    Node *left, *right;
};

Node *build( int in_l, int in_r, int pre_l, int pre_r ) {

    if ( in_l > in_r ) return nullptr;
    Node *root  = new Node();
    root->val   = preorder[ pre_l ];
    int idx     = mapper[ root->val ];
    root->left  = build( in_l, idx - 1, pre_l + 1, pre_l + idx - in_l );
    root->right = build( idx + 1, in_r, pre_l + idx - in_l + 1, pre_r );
    return root;
}

vector<int> postorder;
void dfs( Node *root ) {
    if ( root == nullptr ) return;
    dfs( root->left ), dfs( root->right );
    postorder.push_back( root->val );
}

int main() {

    stack<int> stk;
    int n = 0;
    cin >> n;

    // 主要是这里, 没有认出来这里的 push pop 是中序遍历的过程
    for ( int i = 0; i < n * 2; i++ ) {
        string op;
        cin >> op;
        if ( op == "Push" ) {
            int n;
            cin >> n;
            stk.push( n );
            preorder.push_back( n );
        } else if ( op == "Pop" ) {
            mapper[ stk.top() ] = inorder.size();
            inorder.push_back( stk.top() );
            stk.pop();
        }
    }

    Node *root = build( 0, n - 1, 0, n - 1 );
    dfs( root );

    cout << postorder[ 0 ];
    for ( int i = 1; i < postorder.size(); i++ ) {
        cout << " " << postorder[ i ];
    }
    return 0;
}