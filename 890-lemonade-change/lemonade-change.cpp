class Solution {
public:
    bool lemonadeChange(vector<int>& a) {
        map <int,int> mp;
        for(int i=0;i<a.size();i++){
            ++mp[a[i]];
            if(a[i]==10){
                if(mp[5]<1)return false;
                else --mp[5];
            }
            else if(a[i]==20){
                if(mp[10]>=1 and mp[5]>=1){
                    --mp[10];
                    --mp[5];
                }
                else if(mp[5]>=3)mp[5]-=3;
                else return false;
            }
        }
        return true;
    }
};