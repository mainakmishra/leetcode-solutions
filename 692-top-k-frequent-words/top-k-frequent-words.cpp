class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map <string,int> mp;
        for(auto &i:words)++mp[i];
        map <int,vector<string>,greater<int>> mp2;
        for(auto &i:mp){
            mp2[i.second].push_back(i.first);
        }
        int count=0;
        vector <string> ans;
        for(auto &i:mp2){
            sort(i.second.begin(),i.second.end());
            for(auto &it:i.second){
                ans.push_back(it);
                ++count;
                if(count==k)return ans;
            }
        }
        return ans;
        

        
    }
};