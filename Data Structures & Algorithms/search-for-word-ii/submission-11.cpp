class Solution {
public:
    struct TrieNode {
        bool isEndNode;
        vector<TrieNode*> trie{26, nullptr};
    };
    class PrefixTree {
    public:
        TrieNode* root;

        PrefixTree() {
            root = new TrieNode();
        }
        
        void insert(string word) {
            TrieNode* node = this->root;
            for(char c: word) {
                if(node->trie[c-'a'] == nullptr) {
                    node->trie[c-'a'] = new TrieNode();
                } 
                node = node->trie[c-'a'];
            }
            node->isEndNode = true;
        }
    };

    vector<vector<bool>> visited;
    string path;
    vector<string> wordsFound;

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        PrefixTree tree = PrefixTree();
        int m = board.size(), n = board[0].size();
        wordsFound={};
        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        for(string word: words) {
            tree.insert(word);
        }

        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                dfs(board, tree.root, i, j, m, n);
            }
        }

        return wordsFound;
    }

    void dfs(vector<vector<char>>& board, TrieNode* node, int i, int j, int m, int n) {
        if (i < 0 || i >=m || j < 0 || j >= n || visited[i][j] || node->trie[board[i][j] - 'a'] == nullptr) {
            return;
        }
        visited[i][j] = true;
        path.push_back(board[i][j]);
        TrieNode *nextNode = node->trie[board[i][j] - 'a'];
        if (nextNode->isEndNode) {
            wordsFound.push_back(path);
            nextNode->isEndNode = false; // Prevent duplicates
        }
        dfs(board, nextNode,i-1, j,m,n);
        dfs(board, nextNode,i+1, j,m,n);
        dfs(board, nextNode,i, j-1,m,n);
        dfs(board, nextNode,i, j+1,m,n);
        path.pop_back();
        visited[i][j] = false;
    }
};
