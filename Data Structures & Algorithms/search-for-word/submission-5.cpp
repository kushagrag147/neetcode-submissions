class Solution {
public:
    vector<vector<bool>> visited{10, vector<bool>(10, false)};
    bool haveFound = false;
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for(int i =0; i<m;i++) {
            for (int j = 0; j<n;j++) {
                dfs(board, word, i,j,m,n);
            }
        }
        
        return haveFound;
    }

    void dfs(vector<vector<char>>& board, string word, int i, int j, int m, int n) {
        // cout<<i<<" "<<j<<" "<<word<<"\n";
        if (word == "") {
            // cout<<i<<" "<<j<<"\n";
            haveFound = true;
            return;
        }

        if (haveFound || i < 0 || i >=m || j < 0 || j >= n || visited[i][j]) {
            return;
        }
        visited[i][j] = true;
        string tempWord = word.substr(1, word.size()-1);
        if (board[i][j] == word[0]) {
            dfs(board, tempWord,i-1, j,m,n);
            dfs(board, tempWord,i+1, j,m,n);
            dfs(board, tempWord,i, j-1,m,n);
            dfs(board, tempWord,i, j+1,m,n);
        }

        visited[i][j] = false;
        
    }
};
