class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        priority_queue < pair <int, pair <int,int>> , vector <pair < int, pair <int,int> > >,greater <pair < int,pair <int,int>> > > pq;
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto it=pq.top();
            int d=it.first;
            int row=it.second.first;
            int col=it.second.second;
            pq.pop();
            int x[]={-1,1,0,0};
            int y[]={0,0,-1,1};
            for(int i=0;i<4;i++){
                int dx=row+x[i],dy=col+y[i];
                if(dx>=0 and dx<n and dy>=0 and dy<m){
                    int x=max(abs(grid[dx][dy]-grid[row][col]),d);
                    if(x<dist[dx][dy]){
                        dist[dx][dy]=x;
                        pq.push({x,{dx,dy}});
                    }

                }
            }
        }
        int ans=dist[n-1][m-1];
        if(ans==1e9)return -1;
        else return ans;
    }
};