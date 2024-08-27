class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector <double> dist(n);
        vector <pair<int,double>> adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        priority_queue <pair<double,int>> pq;
        pq.push({1.0,start});
        while(!pq.empty()){
            auto it=pq.top();
            int index=it.second;
            double prob=it.first;
            pq.pop();
            for(auto &i:adj[index]){
                double d=i.second;
                int idx=i.first;
                if(prob*d>dist[idx]){
                    dist[idx]=prob*d;
                    pq.push({dist[idx],idx});
                }
            }
        }
        if(dist[end]==-1)return 0;
        return dist[end];
    }
};