//
//  Leetcode208.cpp
//  Xcode
//
//  Created by Jimmy on 2019/11/25.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

//    class Trie {
//    public:
//        set<string> m_set;
//        /** Initialize your data structure here. */
//        Trie() {
//
//        }
//
//        /** Inserts a word into the trie. */
//        void insert(string word) {
//            m_set.insert(word);
//        }
//
//        /** Returns if the word is in the trie. */
//        bool search(string word) {
//            return m_set.count(word) > 0;
//        }
//
//        /** Returns if there is any word in the trie that starts with the given prefix. */
//        bool startsWith(string prefix) {
//            vector<string> vec(m_set.begin(), m_set.end());
//            int l = 0, r = (int)vec.size()-1;
//            while (l <= r) {
//                int mid = (l + r) / 2;
//                string s = vec[mid];
//                if (s.substr(0,prefix.size()) == prefix) {
//                    return true;
//                }else if (s.substr(0,prefix.size()) > prefix) {
//                    r = mid - 1;
//                } else {
//                    l = mid + 1;
//                }
//            }
//
//            return false;
//        }
//    };

class Trie {
public:
    struct TrieNode {
        TrieNode *ch[26] = {nullptr};
        bool isEnd;
    };

    TrieNode *root = nullptr;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode *temp = root;
        for (char c : word) {
            if (temp->ch[c-'a'] == nullptr) {
                temp->ch[c-'a'] = new TrieNode();
            }
            temp = temp->ch[c-'a'];
        }
        temp->isEnd = true;
    }

    bool search(string word) {
        TrieNode *temp = root;
        for(char c : word) {
            if (temp->ch[c-'a'] == nullptr) {
                return false;
            }
            temp = temp->ch[c-'a'];
        }
        return temp->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode *temp = root;
        for(char c : prefix) {
            if (temp->ch[c-'a'] == nullptr) {
                return false;
            }
            temp = temp->ch[c-'a'];
        }
        return true;
    }
};

    // 自定义一个树， 实现树的插入字符串，查找字符串，判断字符串是否包含以字符串开头的字符串
    void Leetcode::main_208() {
        Trie trie = Trie();
        trie.insert("apple");
        cout << trie.search("apple") << endl;   // returns true
        cout << trie.search("app") << endl;     // returns false
        trie.insert("pple");
        trie.insert("aple");
        trie.insert("pappaple");
        trie.insert("abaple");
        trie.insert("aass");
        trie.insert("avva");
        trie.insert("aaaa");
        cout << trie.startsWith("app") << endl; // returns true
        trie.insert("app");
        cout << trie.search("app") << endl;     // returns true
    }
}
