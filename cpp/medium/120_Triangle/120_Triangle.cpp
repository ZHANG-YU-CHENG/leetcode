/**
 * 
 * Given a triangle array, return the minimum path sum from top to bottom.
 * For each step, you may move to an adjacent number of the row below. 
 * More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
 * 
 * 
 * Example 1:
 * Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
 * Output: 11
 * Explanation: The triangle looks like:
 *    2
 *   3 4
 *  6 5 7
 * 4 1 8 3
 * The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
 * 
 * Example 2:
 * Input: triangle = [[-10]]
 * Output: -10
 * 
 * 
 * Constraints:
 * 1 <= triangle.length <= 200
 * triangle[0].length == 1
 * triangle[i].length == triangle[i - 1].length + 1
 * -10^4 <= triangle[i][j] <= 10^
 * 
 * 
 * Follow up: Could you do this using only O(n) extra space, where n is the total number of rows in the triangle?
 * 
 */

#include <vector>
using namespace std;


//DFS sol
/*
class Solution {
private:
    int minimumTotalDFS(vector<vector<int>>& triangle, int row, int col) {
        if(row == triangle.size()-1)
            return triangle[row][col];
        int left = minimumTotalDFS(triangle, row+1, col);
        int right = minimumTotalDFS(triangle, row+1, col+1);
        return triangle[row][col] + min(left, right);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        return minimumTotalDFS(triangle, 0, 0);
    }
};
*/

//DP sol
/*
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i=0; i<n; ++i) {
            dp[n-1][i] = triangle[n-1][i];
        }

        for(int i=n-2; i>=0; --i) {
            for(int j=0; j<=i; ++j) {
                dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }

        return dp[0][0];
    }
};
*/


//DP sol O(n) space complexity
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(triangle[n-1]);

        for(int i=n-2; i>=0; --i) {
            for(int j=0; j<=i; ++j) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
            }
        }

        return dp[0];
    }
};