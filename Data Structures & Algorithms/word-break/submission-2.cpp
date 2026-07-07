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

            bool search(string word) {
                TrieNode* node = this->root;
                for(char c: word) {
                    if (node->trie[c-'a'] == nullptr) {
                        return false;
                    }
                    node = node->trie[c-'a'];
                }
                return node->isEndNode;
            }
    };

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        PrefixTree *tree = new PrefixTree();
        vector<bool> dp(n+1, false);
        dp[n] = true;
        for(string word: wordDict) {
            tree->insert(word);
        }

        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                string subStr = s.substr(i, j-i+1);
                dp[i] = dp[i] || (tree->search(subStr) && dp[j+1]);
            }
        }

        // checkString(s, 0, n, dp, tree->root, tree);
        
        return dp[0];
    }

    // void checkString(string s, int index, int n, vector<bool> &dp, TrieNode *node, PrefixTree *prefixTree) {
    //     if (!node || index >= n) {
    //         // cout<<"Found: "<<index<<" char: \n";
    //         return;
    //     }

    //     TrieNode *curNode = node->trie[s[index] - 'a'];

    //      if (!curNode) {
    //         return;
    //     }
        
    //     if (curNode->isEndNode) {
    //         // cout<<"Found: "<<index<<" char: "<<s[index]<<"\n";
    //         dp[index] = true;
    //         checkString(s, index+1, n, dp, prefixTree->root, prefixTree);
    //     }

    //     checkString(s, index+1, n, dp, curNode, prefixTree);
        
    // }
};
