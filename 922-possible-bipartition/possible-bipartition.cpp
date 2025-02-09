class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        for(auto &i:dislikes){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector <int> color(n+1,-1);
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                queue <int> q;
                q.push(i);
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    for(auto &j:adj[node]){
                        if(color[j]==-1){
                            color[j]=!color[node];
                            q.push(j);
                        }
                        else{
                            if(color[j]==color[node]){
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};