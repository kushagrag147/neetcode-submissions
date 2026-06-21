class WordDictionary {
public:
    struct TrieNode {
        bool isEndNode;
        vector<TrieNode*> trie{26, nullptr};
    };

    TrieNode* root;
    
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
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
        return searchInTrie(this->root, word, 0);
    }

    bool searchInTrie(TrieNode* node, string word, int i) {
        if (i >= word.size()) {
            // cout<<i<<" "<<node->isEndNode;
            return node->isEndNode;
        }
        // cout<<i<<" "<<word[i]<<"\n";
        if (word[i] == '.') {
            for (int j = 0; j < 26; j++) {
                if (node->trie[j]) {
                    bool check = searchInTrie(node->trie[j], word, i+1);
                    if (check) {
                        return true;
                    }
                }
            }
        } else if(node->trie[word[i]-'a'] != nullptr) {
            return searchInTrie(node->trie[word[i]-'a'], word, i+1);
        }

        return false;
    }
};
