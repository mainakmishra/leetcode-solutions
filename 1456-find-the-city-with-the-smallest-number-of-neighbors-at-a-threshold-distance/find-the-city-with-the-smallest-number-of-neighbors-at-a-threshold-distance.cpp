class Solution {
public:

    int findTheCity(int n, vector<vector<int>>& edges, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &i:edges){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        vector <pair<int,int>> ans;
        for(int i=0;i<n;i++){
            vector<int> dist(n,1e9);
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            pq.push({0,i});
            dist[i]=0;
            while(!pq.empty()){
                auto it=pq.top();
                int d=it.first;
                int node=it.second;
                pq.pop();
                for(auto &i:adj[node]){
                    int node2=i.first;
                    int dis=i.second;
                    if(d+dis<dist[node2]){
                        dist[node2]=d+dis;
                        pq.push({dist[node2],node2});
                    }
                }
            }
            int count=0;
            for(int j=0;j<n;j++){
                if(i!=j and dist[j]<=k)++count;
            }
            ans.push_back({count,i});
        }
        sort(ans.begin(),ans.end());
        int x=ans[0].first;
        int city=-1;
        for(auto &i:ans){
            if(i.first==x)city=max(city,i.second);
            else break;
        }
        return city;
        
    }
};