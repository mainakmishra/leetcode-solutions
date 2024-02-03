class Solution {
public:
    vector<int> grayCode(int n) {
        vector <int> graycode(1<<n);
        for(int i=0;i<(1<<n);i++){
            graycode[i]=i^(i>>1);
        }
        return graycode;
    }
};