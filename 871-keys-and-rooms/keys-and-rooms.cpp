class Solution {
public:
    void dfs(int vertex,vector <int> &vis,vector<vector<int>>& rooms){
        vis[vertex]=1;
        for(auto &i:rooms[vertex]){
            if(!vis[i]){
                dfs(i,vis,rooms);
            }
        }
    }


    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector <int> vis(n,0);
        vis[0]=1;
        for(auto &i:rooms[0]){
            vis[i]=true;
            for(auto &j:rooms[i]){
                dfs(j,vis,rooms);
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i])return false;
        }
        return true;
    }
};