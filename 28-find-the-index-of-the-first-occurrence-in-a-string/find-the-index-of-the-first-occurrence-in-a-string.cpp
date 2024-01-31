class Solution {
public:
    int strStr(string text, string pat) {
        int n1=text.length(),n2=pat.length();
        for(int i=0;i<n1;i++){
            if(n1-i>=n2){
                if(text.substr(i,n2)==pat){
                    return i;
                }
            }
        }
        return -1;
    }
};