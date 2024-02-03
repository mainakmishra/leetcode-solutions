class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord==endWord)return 0;
        unordered_set <string> st;
        for(auto &i:wordList)st.insert(i);
        queue <pair<string,int>> q;
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty()){
            string word=q.front().first;
            int len=q.front().second;
            q.pop();
            if(word==endWord)return len;
            for(int i=0;i<word.length();i++){
                for(char j='a';j<='z';j++){
                    string ns=word.substr(0,i)+j+word.substr(i+1);
                    if(st.find(ns)!=st.end()){
                        q.push({ns,len+1});
                        st.erase(ns);
                    }
                }
            }
        }
        return 0;
    }
};