class Solution {

    void dfs(vector<vector<char>>& grid,int x, int y,int r,int c){
        if(x<0||y<0||x>=r||y>=c||grid[x][y]!='1'){
            return;
        }
        grid[x][y]='2';
        dfs(grid,x+1,y,r,c);
        dfs(grid,x,y+1,r,c);
        dfs(grid,x-1,y,r,c);
        dfs(grid,x,y-1,r,c);
    }



public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ++cnt;
                    dfs(grid,i,j,n,m);
                }
            }
        }
        return cnt;
    }
};