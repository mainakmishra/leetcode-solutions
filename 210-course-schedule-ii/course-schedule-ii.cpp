class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& course) {
        vector<vector<int>> adj(n);
        for(auto &i:course){
            adj[i[1]].push_back(i[0]);
        }
        vector <int> indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue <int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector <int> ans;
        while(!q.empty()){
            int node=q.front();
            ans.push_back(node);
            q.pop();
            for(auto &it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        if(ans.size()==n)return ans;
        else return {};

    }
};