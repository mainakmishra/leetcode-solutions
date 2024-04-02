class Solution {
public:
    Solution(){
        ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
    }
    bool isIsomorphic(string s, string t) {
        unordered_map <char,set<char>> mp,mp2;
        for(int i=0;i<s.length();i++){
            mp[s[i]].insert(t[i]);
            mp2[t[i]].insert(s[i]);
        }
        for(auto &i:mp){
            if(i.second.size()>1)return false;
        }
        for(auto &i:mp2){
            if(i.second.size()>1)return false;
        }
        return true;
    }
};