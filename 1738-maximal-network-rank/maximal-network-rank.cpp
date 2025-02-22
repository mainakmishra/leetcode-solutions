class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<set<int>> graph(n);
        for(auto &i:roads){
            graph[i[0]].insert(i[1]);
            graph[i[1]].insert(i[0]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j!=i){
                    int x=graph[i].size()+graph[j].size();
                    if(graph[i].find(j)!=graph[i].end())--x;
                    ans=max(ans,x);
                }
            }
        }
        return ans;
        
        
    }
};