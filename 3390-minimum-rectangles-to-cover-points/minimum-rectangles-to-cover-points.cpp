class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        int n=points.size();
        int p[n];
        for(int i=0;i<n;i++){
            p[i]=points[i][0];
        }
        sort(p,p+n);
        int i=0;
        int count=0;
        while(i<n){
            int x=upper_bound(p+i,p+n,p[i]+w)-p;
            i=x;
            count++;
        }
        return count;
    }
};