class Solution {
public:
    void dfs(int row,int col,int color,int ini,vector<vector<int>>& image,int n,int m){
        image[row][col]=color;
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int x=row+delr[i],y=col+delc[i];
            if(x>=0 and x<n and y>=0 and y<m and image[x][y]==ini){
                dfs(x,y,color,ini,image,n,m);
            }
        }
    }



    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size(),m=image[0].size();
        int initial_color=image[sr][sc];
        if(initial_color==color)return image;
        dfs(sr,sc,color,initial_color,image,n,m);
        return image;
    }
};