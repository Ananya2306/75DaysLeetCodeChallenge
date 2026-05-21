class Solution {
private:
    struct Node {
        int child[26];
        int end;
        unsigned char deg;

        Node() : end(-1), deg(0) {
            memset(child, -1, sizeof(child));
        }
    };

    vector<Node> trie;
    vector<string>* wordsPtr;
    vector<string> ans;

    vector<char> cells;
    vector<array<int, 4>> nbr;
    vector<unsigned char> nbrCnt;
    vector<int> posByChar[26];

    int totalCells;

    inline void insertWord(const string& s, int id) {
        int p = 0;
        for (char ch : s) {
            int k = ch - 'a';
            if (trie[p].child[k] == -1) {
                trie[p].child[k] = (int)trie.size();
                trie.emplace_back();
                ++trie[p].deg;
            }
            p = trie[p].child[k];
        }
        trie[p].end = id;
    }

    void dfs(int pos, int parent) {
        int k = cells[pos] - 'a';
        int node = trie[parent].child[k];
        if (node == -1) return;

        int id = trie[node].end;
        if (id != -1) {
            ans.push_back((*wordsPtr)[id]);
            trie[node].end = -1;
        }

        char saved = cells[pos];
        cells[pos] = '#';

        unsigned char cnt = nbrCnt[pos];
        for (int t = 0; t < cnt; ++t) {
            int np = nbr[pos][t];
            char c = cells[np];
            if (c != '#' && trie[node].child[c - 'a'] != -1) {
                dfs(np, node);
            }
        }

        cells[pos] = saved;

        if (trie[node].end == -1 && trie[node].deg == 0) {
            trie[parent].child[k] = -1;
            --trie[parent].deg;
        }
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = (int)board.size();
        int m = (int)board[0].size();
        totalCells = n * m;

        wordsPtr = &words;
        ans.clear();
        trie.clear();
        trie.emplace_back();

        cells.assign(totalCells, 0);
        nbr.assign(totalCells, { -1, -1, -1, -1 });
        nbrCnt.assign(totalCells, 0);
        for (int c = 0; c < 26; ++c) posByChar[c].clear();

        int freq[26] = {};
        bool adj[26][26] = {};

        auto id = [&](int x, int y) { return x * m + y; };

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int p = id(i, j);
                char ch = board[i][j];
                cells[p] = ch;
                ++freq[ch - 'a'];
                posByChar[ch - 'a'].push_back(p);

                if (i > 0) nbr[p][nbrCnt[p]++] = id(i - 1, j);
                if (i + 1 < n) nbr[p][nbrCnt[p]++] = id(i + 1, j);
                if (j > 0) nbr[p][nbrCnt[p]++] = id(i, j - 1);
                if (j + 1 < m) nbr[p][nbrCnt[p]++] = id(i, j + 1);
            }
        }

        for (int p = 0; p < totalCells; ++p) {
            int a = cells[p] - 'a';
            for (int t = 0; t < nbrCnt[p]; ++t) {
                int q = nbr[p][t];
                int b = cells[q] - 'a';
                adj[a][b] = true;
            }
        }

        for (int i = 0; i < (int)words.size(); ++i) {
            const string& w = words[i];
            int len = (int)w.size();
            if (len > totalCells) continue;

            int need[26] = {};
            bool ok = true;

            for (char ch : w) {
                int k = ch - 'a';
                ++need[k];
                if (need[k] > freq[k]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;

            for (int j = 1; j < len; ++j) {
                if (!adj[w[j - 1] - 'a'][w[j] - 'a']) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;

            string t = w;
            if (freq[w.front() - 'a'] > freq[w.back() - 'a']) {
                reverse(t.begin(), t.end());
            }
            insertWord(t, i);
        }

        ans.reserve(words.size());

        for (int c = 0; c < 26 && trie[0].deg > 0; ++c) {
            if (trie[0].child[c] == -1) continue;
            for (int pos : posByChar[c]) {
                if (trie[0].child[c] == -1) break;
                dfs(pos, 0);
            }
        }

        return ans;
    }
};