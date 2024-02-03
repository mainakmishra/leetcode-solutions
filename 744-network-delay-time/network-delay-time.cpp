class Solution {
private:

public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &i:times){
            adj[i[0]].push_back({i[1],i[2]});
        }
        vector <int> vis(n+1,0);
        vector <int> dist(n+1,1e9);
        dist[k]=0;
        dist[0]=0;
        queue <pair<int,int>> q;
        q.push({k,0});
        vis[k]=1;
        map <int,int> mp;
        while(!q.empty()){
            int node=q.front().first;
            int d=q.front().second;
            q.pop();
            
            for(auto &i:adj[node]){
                int x=i.first;
                
                if(dist[x]>d+i.second){
                    dist[x]=d+i.second;
                    q.push({x,dist[x]});
                }
            }
        }
        int x=*max_element(dist.begin()+1,dist.end());
        if(x!=1e9)return x;
        else return -1;
    }
};