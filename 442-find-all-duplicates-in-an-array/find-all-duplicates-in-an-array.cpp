class Solution {
public:
    vector<int> findDuplicates(vector<int>& a) {
        vector <int> ans;
        int n=a.size();
        for(int i=0;i<n;i++){
            int idx=abs(a[i])-1;
            if(a[idx]<0)ans.push_back(abs(a[i]));
            else a[idx]*=-1;
        }
        return ans;
    }
};