#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
  public:
    int dx[ 4 ] = { 0, 1, 0, -1 }, dy[ 4 ] = { 1, 0, -1, 0 };
    int row = 0, col = 0;
    bool in_bround( int x, int y ) {
        return x >= 0 && x < row && y >= 0 && y < col;
    }
    vector<int> spiralOrder( vector<vector<int>> &matrix ) {
        vector<vector<bool>> st( matrix.size(),
                                 vector<bool>( matrix[ 0 ].size() ) );
        vector<int> ans;

        row = matrix.size(), col = matrix[ 0 ].size();

        int i = 0, j = 0, cnt = 0;
        int xy_dir = 0;
        for ( int cnt = 0; cnt < row * col; cnt++ ) {
            if ( !in_bround( i, j ) || st[ i ][ j ] ) {
                i -= dx[ xy_dir ], j -= dy[ xy_dir ];
                xy_dir = ( xy_dir + 1 ) % 4;
                i += dx[ xy_dir ], j += dy[ xy_dir ];
            }
            st[ i ][ j ] = true;
            ans.push_back( matrix[i][j] );
            i += dx[ xy_dir ], j += dy[ xy_dir ];
        }

        return ans;
    }
};
// @lc code=end
