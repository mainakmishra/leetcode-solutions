class Solution {
public:
    vector<int> partitionLabels(string s) {
        map <char,int> mp;
        int i,n=s.length();
        for(i=0;i<n;i++){
            mp[s[i]]=i;
        }
        vector <int> ans;
        int start=0,end=mp[s[0]];
        for(i=0;i<n;i++){
            if(i<end)end=max(end,mp[s[i]]);
            if(i==end){
                ans.push_back(end-start+1);
                if(i<n-1)end=mp[s[i+1]];
                start=i+1;
            }
        }
        return ans;
    }
};