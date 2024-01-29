class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>& grid,int n,int m){
        grid[row][col]=0;
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int x=row+delr[i],y=col+delc[i];
            if(x<n and y<m and x>=0 and y>=0 and grid[x][y]==1){
                dfs(x,y,grid,n,m);
            }
        }

    }


    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    if(i==0 or i==n-1 or j==0 or j==m-1){
                        dfs(i,j,grid,n,m);
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ++count;
                }
            }
        }
        return count;
    }
};