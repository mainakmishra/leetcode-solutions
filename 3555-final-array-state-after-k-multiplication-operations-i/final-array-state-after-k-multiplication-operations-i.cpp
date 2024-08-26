class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        while(k--){
            auto it=pq.top();
            int min=it.first*multiplier;
            int index=it.second;
            pq.pop();
            pq.push({min,index});
        }
        vector <int> ans(n);
        while(!pq.empty()){
            auto it=pq.top();
            ans[it.second]=it.first;
            pq.pop();
        }
        return ans;
    }
};