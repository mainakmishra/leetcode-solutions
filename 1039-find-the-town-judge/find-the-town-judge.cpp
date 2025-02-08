class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> adj(n+1);
        vector <int> count(n+1,0);
        for(auto &i:trust){
            adj[i[0]].push_back(i[1]);
            count[i[1]]++;
            
        }
        for(int i=1;i<=n;i++){
            if(adj[i].size()==0 && count[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};