class PrefixTree {
public:
    struct TrieNode {
        bool isEndNode;
        vector<TrieNode*> trie{26, nullptr};
    };

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
    
    bool startsWith(string prefix) {
        TrieNode* node = this->root;
        for(char c: prefix) {
            if (node->trie[c-'a'] == nullptr) {
                return false;
            }
            node = node->trie[c-'a'];
        }
        return true;
    }
};
