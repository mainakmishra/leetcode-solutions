class Solution {
public:
    Solution(){
        ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector <vector<pair<int,int>>> adj(n);
        for(auto &i:flights){
            adj[i[0]].push_back({i[1],i[2]});
        }
        vector <int> dist(n,1e9);
        queue <pair<int,pair<int,int>>> q;
        q.push({0,{0,src}});
        dist[src]=0;
        while(!q.empty()){
            auto it=q.front();
            int stops=it.first;
            int d=it.second.first;
            int node=it.second.second;
            q.pop();
            for(auto &i:adj[node]){
                int node2=i.first;
                int di=i.second;
                if(stops+1<=k+1 and d+di<dist[node2]){
                    dist[node2]=d+di;
                    q.push({stops+1,{d+di,node2}});
                }
            }
        }
        return dist[dst]==1e9?-1:dist[dst];
    }
};