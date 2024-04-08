class Solution {
public:    
    string getSmallestString(string s, int k) {
        if(k == 0) return s;
        int diff=0;
        for(int i=0;i<s.size();i++){
            diff = min('z'-s[i]+1,s[i]-'a');
            if(k>=diff){
                s[i] = 'a';
                k -= diff;
            }else if(k < diff){
                s[i] = s[i]-k;
                k=0;
            }           
        }
        return s;
    }
};