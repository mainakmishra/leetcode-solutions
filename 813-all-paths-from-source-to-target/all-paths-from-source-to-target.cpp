class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int node, vector<vector<int>>& graph, vector<int> &visited, vector<int> &v){
        visited[node]=1;
        v.push_back(node);
        if(node==graph.size()-1)ans.push_back(v);
        for(auto &i:graph[node]){
            if(!visited[i]){
                dfs(i,graph,visited,v);
            }
        }
        visited[node]=0;
        v.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector <int> visited(n,0),v;
        dfs(0,graph,visited,v);
        return ans;
    }
};