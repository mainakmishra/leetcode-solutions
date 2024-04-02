class Solution {
public:

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int sumgas=0,sumcost=0;
        int current=0,idx=0;
        for(int i=0;i<n;i++){
            sumgas+=gas[i];
            sumcost+=cost[i];
            current+=gas[i]-cost[i];
            if(current<0){
                idx=i+1;
                current=0;
            }
        }
        if(sumgas>=sumcost)return idx;
        else return -1;
    }
};