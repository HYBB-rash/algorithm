#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
/*
 * @lc app=leetcode.cn id=722 lang=cpp
 *
 * [722] 删除注释
 */

// @lc code=start
class Solution {
  public:
    int remove_cnt = 0;
    vector<string> remove( vector<string> &source ) {
        vector<string> ans;
        for ( int i = 0; i < source.size(); i++ ) {
            int posi   = -1;
            int posi_a = source[ i ].find( "//" );
            int posi_b = source[ i ].find( "/*" );

            posi_a = posi_a == source[ i ].npos ? -1 : posi_a;
            posi_b = posi_b == source[ i ].npos ? -1 : posi_b;

            if ( posi_a == -1 && posi_b == -1 ) {
                ans.push_back( source[ i ] );
                continue;
            }
            if ( posi_a == -1 )
                posi = posi_b;
            else if ( posi_b == -1 )
                posi = posi_a;
            else
                posi = min( posi_a, posi_b );

            // cout << source[ i ][ posi ] << source[ i ][ posi + 1 ] << endl;

            remove_cnt++;
            if ( source[ i ][ posi + 1 ] == '/' ) {
                // cout << source[ i ][ posi ] << source[ i ][ posi + 1 ]
                //      << source[ i ][ posi + 2 ] << endl;
                string code = source[ i ].substr( 0, posi );

                // cout << code << endl;

                if ( code.empty() ) continue;
                // cout << code << endl;

                
                ans.push_back( code );
            } else if ( source[ i ][ posi + 1 ] == '*' ) {
                string code = source[ i ].substr( 0, posi );

                string init_str = source[ i ].substr( posi + 2 );

                // cout << "init_str: " << init_str << endl;

                int cnt = 0, tail_posi = init_str.find( "*/" );
                while ( tail_posi == source[ i + cnt ].npos )
                    tail_posi = source[ i + ( ++cnt ) ].find( "*/" );

                if ( cnt == 0 ) tail_posi += posi + 2;
                // cout << "get cnt: " << cnt << endl;
                // cout << "tail posi: " << tail_posi + posi + 2 << endl;

                string tail_code = source[ i + cnt ].substr( tail_posi + 2 );
                string ans_code  = code + tail_code;

                // cout << ans_code << endl;

                if ( !ans_code.empty() ) ans.push_back( ans_code );
                i += cnt;
            }
        }
        return ans;
    }
    vector<string> removeComments( vector<string> &source ) {
        auto ans = remove( source );
        while ( remove_cnt != 0 ) {
            remove_cnt = 0;
            ans = remove( ans );
        }
        return ans;
    }
};
// @lc code=end
