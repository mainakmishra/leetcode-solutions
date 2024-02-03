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
                char start=word[i];
                for(char j='a';j<='z';j++){
                    word[i]=j;
                    if(st.find(word)!=st.end()){
                        q.push({word,len+1});
                        st.erase(word);
                    }
                }
                word[i]=start;
            }
        }
        return 0;
    }
};