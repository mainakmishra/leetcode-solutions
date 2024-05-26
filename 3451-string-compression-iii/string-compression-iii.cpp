class Solution {
public:
    string compressedString(string word) {
        int n=word.length();
        string ans="";
        int count=1;
        for(int i=0;i<n;i++){
            if(i==n-1 or word[i]!=word[i+1] or count>=9){
                ans+=to_string(count)+word[i];
                count=1;
            }
            else count++;
        }
        return ans;
    }
};