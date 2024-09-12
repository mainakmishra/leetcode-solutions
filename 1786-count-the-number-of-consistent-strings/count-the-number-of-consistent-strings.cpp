class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map <char,int> mp;
        for(auto &i:allowed)++mp[i];
        int count=0;
        for(auto &i:words){
            int flag=1;
            for(auto &j:i){
                if(mp[j]==0){
                    flag=0;
                    break;
                }
            }
            if(flag)++count;
        }
        return count;
    }
};