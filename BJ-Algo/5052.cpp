#include <iostream>

using namespace std;

class Trie {
  public:
    struct TrieNode {
        TrieNode *node[10];
        bool isFinish;

        TrieNode() { isFinish = false; }
    };

    Trie() { root_ = new TrieNode(); }

    bool Insert(const string &s) {
        TrieNode *tmp = root_;

        for (int i = 0; i < s.length(); ++i) {
            int idx = s[i] - '0';
            if (tmp->node[idx] == nullptr) {
                tmp->node[idx] = new TrieNode();
            }
            if (tmp->isFinish) {
                return false;
            }
            tmp = tmp->node[idx];
        }
        tmp->isFinish = true;

        for (int i = 0; i < 10; ++i) {
            if (tmp->node[i] != nullptr) {
                return false;
            }
        }
        return true;
    }

  private:
    TrieNode *root_;
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        Trie root;
        bool isConsistent = true;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            if (!isConsistent) {
                continue;
            }

            if (!root.Insert(s)) {
                isConsistent = false;
            }
        }
        cout << ((isConsistent) ? "YES" : "NO") << '\n';
    }
}
