/*
 * @lc app=leetcode.cn id=1034 lang=cpp
 *
 * [1034] 边框着色
 */

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
  public:
    bool connect_block[ 100 ][ 100 ], edge_block[ 100 ][ 100 ];
    bool st[ 100 ][ 100 ];
    int dx[ 4 ] = { 0, 1, 0, -1 }, dy[ 4 ] = { 1, 0, -1, 0 };
    void dfs( vector<vector<int>> &grid, int row, int col ) {
        connect_block[ row ][ col ] = true;
        st[ row ][ col ]            = true;
        for ( int i = 0; i < 4; i++ ) {
            int n_row = row + dx[ i ], n_col = col + dy[ i ];
            if ( n_row < 0 || n_row >= grid.size() ) continue;
            if ( n_col < 0 || n_col >= grid[ 0 ].size() ) continue;
            if ( st[ n_row ][ n_col ] ) continue;
            if ( grid[ row ][ col ] == grid[ n_row ][ n_col ] ) {
                dfs( grid, n_row, n_col );
            }
        }
    }
    vector<vector<int>> colorBorder( vector<vector<int>> &grid, int row,
                                     int col, int color ) {
        dfs( grid, row, col );
        for ( int i = 0; i < grid.size(); i++ ) {
            for ( int j = 0; j < grid[ 0 ].size(); j++ ) {
                if ( connect_block[ i ][ j ] == false ) continue;
                if ( i == 0 || i == grid.size() - 1 )
                    edge_block[ i ][ j ] = true;
                if ( j == 0 || j == grid[ 0 ].size() - 1 )
                    edge_block[ i ][ j ] = true;
                for ( int k = 0; k < 4; k++ ) {
                    int n_i = i + dx[ k ], n_j = j + dy[ k ];
                    if ( n_i < 0 || n_i >= grid.size() ) continue;
                    if ( n_j < 0 || n_j >= grid[ 0 ].size() ) continue;
                    if ( connect_block[ n_i ][ n_j ] == false ) {
                        edge_block[ i ][ j ] = true;
                        break;
                    }
                }
            }
        }
        for ( int i = 0; i < grid.size(); i++ ) {
            for ( int j = 0; j < grid[ 0 ].size(); j++ ) {
                if ( edge_block[ i ][ j ] ) grid[ i ][ j ] = color;
            }
        }
        return grid;
    }
};
// @lc code=end
