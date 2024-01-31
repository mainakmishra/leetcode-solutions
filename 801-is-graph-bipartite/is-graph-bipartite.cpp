class Solution {
public:
    int dfs(int vertex, vector<vector<int>> &graph, vector <int> &color,int c){
        color[vertex]=c;
        for(auto &i:graph[vertex]){
            if(color[i]==-1){
                if(dfs(i,graph,color,!c)==false)return false;
            }
            else{
                if(color[i]==c)return false;
            }
        }
        return true;
    }



    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector <int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(dfs(i,graph,color,0)==false)return false;
            }
        }
        return true;
    }
};