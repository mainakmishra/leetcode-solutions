class Solution {
public:
    void dfs(int vertex,vector<vector<int>> &adj,vector<int> &visited){
        visited[vertex]=1;
        for(auto &i:adj[vertex]){
            if(!visited[i]){
                dfs(i,adj,visited);
            }
        }
    }


    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adj(n);
        vector <int> visited(n,0);
        int i;
        for(i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count=0;
        for(i=0;i<n;i++){
            if(!visited[i]){
                ++count;
                dfs(i,adj,visited);
            }
        }
        return count;
    }
};