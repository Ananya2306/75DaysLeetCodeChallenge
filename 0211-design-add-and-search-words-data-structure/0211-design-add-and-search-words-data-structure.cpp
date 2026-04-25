struct TrieNode {
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        for (int i = 0; i < 26; i++) children[i] = NULL;
        isEnd = false;
    }
};

class WordDictionary {
private:
    TrieNode* root;

    bool dfs(string &word, int index, TrieNode* node) {
        if (index == word.size()) {
            return node->isEnd;
        }

        char ch = word[index];

        if (ch != '.') {
            if (node->children[ch - 'a'] == NULL) return false;
            return dfs(word, index + 1, node->children[ch - 'a']);
        }

        for (int i = 0; i < 26; i++) {
            if (node->children[i] != NULL) {
                if (dfs(word, index + 1, node->children[i])) {
                    return true;
                }
            }
        }

        return false;
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;

        for (char ch : word) {
            if (node->children[ch - 'a'] == NULL) {
                node->children[ch - 'a'] = new TrieNode();
            }
            node = node->children[ch - 'a'];
        }

        node->isEnd = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
};