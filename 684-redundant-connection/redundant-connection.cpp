class Solution {
private:
    void dfs(int vertex, vector<vector<int>> &adj, vector<int> &vis){
        vis[vertex]=1;
        for(auto &i:adj[vertex]){
            if(!vis[i]){
                dfs(i,adj,vis);
            }
        }
    }


public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>> adj(n+1);
        for(auto &i:edges){
            vector <int> vis(n+1,0);
            dfs(i[0],adj,vis);
            if(vis[i[1]]!=0){
                vector <int> ans={i[0],i[1]};
                return ans;
            }
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        return {};
    }
};