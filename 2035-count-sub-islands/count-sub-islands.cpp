class Solution {
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid2, int n, int m, vector<pair<int,int>>& check){
        check.push_back({row,col});
        vis[row][col]=1;
        int dir[]={-1,0,1,0};
        for(int i=0;i<4;i++){
            int delr=row+dir[i];
            int delc=col+dir[(i+1)%4];
            if(delr>=0 and delc>=0 and delr<n and delc<m and grid2[delr][delc]==1 and !vis[delr][delc]){
                dfs(delr,delc,vis,grid2,n,m,check);
            }
        }
    }


public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size(),m=grid1[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1 and !vis[i][j]){
                    vector<pair<int,int>> check;
                    dfs(i,j,vis,grid2,n,m,check);
                    int flag=1;
                    for(auto &i:check){
                        int row=i.first,col=i.second;
                        if(grid1[row][col]!=1){
                            flag=0;
                            break;
                        }
                    }
                    if(flag)count++;
                }
            }
        }
        return count;  


    }
};