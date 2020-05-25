//
//  Leetcode127.cpp
//  Xcode
//
//  Created by Jimmy on 2019/10/28.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    bool isMatchLadder(string a, string b) {
        int count = 0;
        for (int i = 0; i < a.size();i++) {
            if (a[i] != b[i]) count++;
        }
        return count == 1;
    }


    int ladderLength2(string beginWord, string endWord, vector<string>& wordList) {
        vector<string> vec;
        vector<string> words;

        queue<string> q;
        unordered_set<string> s;
        q.push(beginWord);
        s.insert(beginWord);

        int level = 0;
        while(!q.empty()) {
            level++;
            int size = (int)q.size();
            for (int i = 0; i < size; i++) {
                string str = q.front();
                q.pop();
                if (str == endWord) {
                    return level;
                }
                for(int i = 0;i< wordList.size();i++) {
                    if (isMatchLadder(wordList[i], str) &&
                        find(s.begin(), s.end(), wordList[i]) == s.end()) {
                        s.insert(wordList[i]);
                        q.push(wordList[i]);
                    }
                }
            }
        }

        return 0;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(),wordList.end());
        unordered_set<string> s;
        unordered_map<string,int> level;
        queue<string> q;
        q.push(beginWord);
        s.insert(beginWord);
        level[beginWord]=1;

        while(!q.empty()){
            string str = q.front();
            q.pop();

            if(str == endWord){
                return level[str];
            }
            for(int i = 0;i < str.size(); i++) {
                for(char c ='a'; c <= 'z'; c++) {
                    if(c == str[i]) continue;
                    string tmp = str;
                    tmp[i] = c;
                    if(words.count(tmp) && !s.count(tmp)){
                        q.push(tmp);
                        s.insert(tmp);
                        level[tmp] = level[str] + 1;
                    }
                }
            }
        }

        return 0;
    }

    void Leetcode::main_127() {
        vector<string> list1{"hot","dot","dog","lot","log","cog"};
        cout << "5 | " << ladderLength("hit", "cog", list1) << endl;
        vector<string> list2{"a","b","c"};
        //cout << "2 | " << ladderLength("a", "c", list2) << endl;
        vector<string> list3{"hot","dot","dog","lot","log"};
        //cout << "0 | " << ladderLength("hit", "cog", list3) << endl;
        vector<string> list4{"hot","cog","dot","dog","hit","lot","log"};
        //cout << "5 | " << ladderLength("hit", "cog", list4) << endl;
        vector<string> list5{"ts","sc","ph","ca","jr","hf","to","if","ha","is","io","cf","ta"};
        //cout << "4 | " << ladderLength("ta", "if", list5) << endl;

    }
}
