/** 
 * *  @File        :   Acwing142.cpp
 * *  @Time        :   2021/04/15 16:16:50
 * *  @Author      :   hyong
 * *  @Version     :   1.0
 * *  @Contact     :   hyong_cs@outlook.com
 * !  @Description :   daily problem in acwing.
**/
#include <iostream>
#include <unordered_map>
using namespace std;

class Node{
    public:

    unordered_map<char, Node*> sons;
    int tail = 0;
};

int m, n;

void insert(string str, Node *root) {
    for (int i = 0; i < str.size(); i ++) {
        Node *tmp = root->sons[str[i]];
        if (tmp == nullptr) {
            tmp = new Node();
            root->sons[str[i]] = tmp;
        }
        root = tmp;
    }
    root->tail++;
}

int find(string str, Node *root) {
    int cnt = 0;
    for (int i = 0; i < str.size(); i ++) {
        Node *tmp = root->sons[str[i]];
        if (tmp == nullptr) return cnt;
        if (tmp->tail) cnt += tmp->tail;
        root = tmp;
    }
    return cnt;
}

int main () {
    Node *root = new Node();
    cin >> n >> m;
    for (int i = 0 ; i < n; i ++) {
        string str;
        cin >> str;
        insert(str, root);
    }
    for (int i = 0; i < m; i ++) {
        string str;
        cin >> str;
        int res = find(str, root);
        cout << res << endl;
    }
    return 0;
}