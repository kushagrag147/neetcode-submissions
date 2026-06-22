class Solution {
public:
    vector<vector<bool>> visited;
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), islands = 0;
        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    islands++;
                    dfs(grid, i, j, m, n);
                }
            }
        }

        return islands;
    }

    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
        if (i < 0 || i >=m || j < 0 || j >= n || visited[i][j]) {
            return;
        }

        visited[i][j] = true;

        if (grid[i][j] == '0') {
            return;
        }

        dfs(grid, i+1, j, m, n);
        dfs(grid, i-1, j, m, n);
        dfs(grid, i, j+1, m, n);
        dfs(grid, i, j-1, m, n);
    }
};
