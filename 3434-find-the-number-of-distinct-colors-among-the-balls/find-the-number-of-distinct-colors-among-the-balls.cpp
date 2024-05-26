class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map <int,int> mp;
        map <int,int> col;
        vector <int> ans;
        for(auto &i:queries){
            if(mp.find(i[0])!=mp.end()){
                --col[mp[i[0]]];
                if(col[mp[i[0]]]==0)col.erase(mp[i[0]]);
            }
            mp[i[0]]=i[1];
            ++col[i[1]];
            ans.push_back(col.size());
        }
        return ans;
    }
};