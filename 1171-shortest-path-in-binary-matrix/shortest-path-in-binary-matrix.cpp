class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]!=0)return -1;
        int n=grid.size(),m=grid[0].size();
        priority_queue < pair <int, pair <int,int>> , vector <pair < int, pair <int,int> > >,greater <pair < int,pair <int,int>> > > pq;
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=1;
        pq.push({1,{0,0}});
        while(!pq.empty()){
            auto it=pq.top();
            int d=it.first;
            int row=it.second.first;
            int col=it.second.second;
            pq.pop();
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int dx=i+row,dy=j+col;
                    if(dx>=0 and dx<n and dy>=0 and dy<m and grid[dx][dy]==0){
                        if(d+1<dist[dx][dy]){
                            dist[dx][dy]=d+1;
                            pq.push({d+1,{dx,dy}});
                        }
                    }
                }
            }
        }
        int ans=dist[n-1][m-1];
        if(ans==1e9)return -1;
        else return ans;

    }
};