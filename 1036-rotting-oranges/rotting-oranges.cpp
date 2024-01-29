class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue <pair<pair<int,int>,int>> q;
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    visited[i][j]=2;
                }
                else{
                    visited[i][j]=0;
                }
            }
        }
        int tm=0;
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int t=q.front().second;
            tm=max(t,tm);
            q.pop();
            int delr[]={-1,0,1,0};
            int delc[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int x=row+delr[i],y=col+delc[i];
                if(x>=0 and x<n and y>=0 and y<m and visited[x][y]!=2 and grid[x][y]==1){
                    q.push({{x,y},t+1});
                    visited[x][y]=2;
                }
            }
        }
        for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]==1 and visited[i][j]!=2){
                        return -1;
                    }
                }
        }

        return tm;
    }
};