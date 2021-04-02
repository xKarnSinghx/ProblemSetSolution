/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

 

Example 1:


Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        for(int i=1;i<c;i++){
            grid[0][i]+=grid[0][i-1];
        }
         for(int i=1;i<r;i++){
            grid[i][0]+=grid[i-1][0];
        }
        for(int i=1;i<r;i++){
            for(int j=1;j<c;j++){
                grid[i][j]+=min(grid[i-1][j],grid[i][j-1]);
            }
        }
        return grid[r-1][c-1];
    }
};
