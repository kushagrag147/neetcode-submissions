class Solution {
public:
    vector<vector<bool>> pacific;
    vector<vector<bool>> atlantic;
    vector<vector<int>> finalCells;
    vector<vector<bool>> visited;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        finalCells = {};
        pacific = vector<vector<bool>>(m, vector<bool>(n, false));
        atlantic = vector<vector<bool>>(m, vector<bool>(n, false));
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (i == 0 || j == 0) {
                    // cout<<i<<" "<<j<<" "<<pacific[i][j]<<"\n";
                    pacific[i][j] = true;
                } 
                if (i == m-1 || j == n-1) {
                    // cout<<i<<" "<<j<<" "<<atlantic[i][j]<<"\n";
                    atlantic[i][j] = true;
                }
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    dfs(heights, i, j, m, n, pacific);
                } 
            }
        }
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    dfs(heights, i, j, m, n, atlantic);
                } 
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // cout<<i<<" "<<j<<" "<<atlantic[i][j]<<" "<<pacific[i][j]<<"\n";
                if (atlantic[i][j] && pacific[i][j]) {
                    finalCells.push_back({i,j}); 
                }
            }
        }
        return finalCells;
    }

    bool dfs(vector<vector<int>>& heights, int i, int j, int m, int n, vector<vector<bool>> &dp) {
        if ( i < 0 || i >= m || j < 0 || j >= n) {
            return false;
        }

        if (visited[i][j]) {
            return dp[i][j];
        }

        visited[i][j] = true;
 
        if (i+1 < m && heights[i+1][j]<= heights[i][j]) {
            dp[i][j] = dp[i][j] || dfs(heights, i+1, j, m, n, dp);
        }
        if (i-1 >= 0 && heights[i-1][j]<= heights[i][j]) {
            dp[i][j] = dp[i][j] || dfs(heights, i-1, j, m, n, dp);
        }
        if (j+1 < n && heights[i][j+1]<= heights[i][j]) {
            dp[i][j] = dp[i][j] || dfs(heights, i, j+1, m, n, dp);
        }
        if (j-1 >=0 && heights[i][j-1]<= heights[i][j]) {
            dp[i][j] = dp[i][j] || dfs(heights, i, j-1, m, n, dp);
        }

        return dp[i][j];
    }
};
