#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Trie {
  public:
    struct TrieNode {
        unordered_map<char, TrieNode *> node;
        int numChild;

        TrieNode() { numChild = 0; }
    };

    Trie() { root_ = new TrieNode; }

    void Insert(const string &word) {
        TrieNode *temp = root_;
        for (char c : word) {
            if (temp->node.find(c) == temp->node.end()) {
                temp->node[c] = new TrieNode();
            }
            temp->numChild++;
            temp = temp->node[c];
        }
    }

    int FindNumSuf(const string &query) {
        TrieNode *temp = root_;
        for (char c : query) {
            if (c == '?') {
                return temp->numChild;
            }
            if (temp->node.find(c) == temp->node.end()) {
                return 0;
            }
            temp = temp->node[c];
        }
        return 1;
    }

  private:
    TrieNode *root_;
};

bool IsPref(const string &query) {
    if (query[0] == '?') {
        return true;
    }
    return false;
}

string Reverse(const string &str) {
    string reversed;

    for (int i = str.length() - 1; i >= 0; --i) {
        reversed += str[i];
    }
    return reversed;
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;

    unordered_map<int, Trie> m;
    unordered_map<int, Trie> m_rev;
    for (const string &word : words) {
        if (m.find(word.length()) == m.end()) {
            m[word.length()] = Trie();
            m_rev[word.length()] = Trie();
        }
        m[word.length()].Insert(word);
        m_rev[word.length()].Insert(Reverse(word));
    }

    for (const string &query : queries) {
        if (IsPref(query)) {
            if (m_rev.find(query.length()) == m_rev.end()) {
                answer.push_back(0);
            } else {
                int numPref = m_rev[query.length()].FindNumSuf(Reverse(query));
                answer.push_back(numPref);
            }
        } else {
            if (m.find(query.length()) == m.end()) {
                answer.push_back(0);
            } else {
                int numPref = m[query.length()].FindNumSuf(query);
                answer.push_back(numPref);
            }
        }
    }

    return answer;
}
