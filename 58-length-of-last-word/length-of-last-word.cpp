class Solution {
public:
    int lengthOfLastWord(string s) {
        int first=0,second=0,n=s.length();
        for(int i=n-1;i>=0;i--){
            if(s[i]!=' '){
                second=i;
                break;
            }
        }
        for(int i=n-1;i>0;i--){
            if(s[i]!=' ' and s[i-1]==' '){
                first=i;
                break;
            }
        }
        int ans=second-first+1;
        return ans;
    }
};