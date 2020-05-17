#include <string>
#include <unordered_map>

using namespace std;

class Trie {
 public:
  /** Initialize your data structure here. */
  struct TrieNode {
    unordered_map<char, TrieNode *> node;
    bool isFinish;

    TrieNode() { isFinish = false; }
  };

  Trie() {
    root_ = new TrieNode();
    root_->isFinish = false;
  }

  /** Inserts a word into the trie. */
  void insert(string word) {
    TrieNode *tmp = root_;
    for (char c : word) {
      if (tmp->node.find(c) == tmp->node.end()) {
        tmp->node[c] = new TrieNode();
      }
      tmp = tmp->node[c];
    }
    tmp->isFinish = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    TrieNode *tmp = root_;
    for (char c : word) {
      if (tmp->node.find(c) == tmp->node.end()) {
        return false;
      }
      tmp = tmp->node[c];
    }
    return tmp->isFinish;
  }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix) {
    TrieNode *tmp = root_;
    for (char c : prefix) {
      if (tmp->node.find(c) == tmp->node.end()) {
        return false;
      }
      tmp = tmp->node[c];
    }
    return true;
  }

 private:
  TrieNode *root_;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */