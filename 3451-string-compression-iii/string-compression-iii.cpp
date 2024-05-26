class Solution {
public:
    string compressedString(string word) {
        int n=word.length();
        string ans="";
        int count=1;
        for(int i=0;i<n;i++){
            if(i==n-1){
                ans+=to_string(count);
                ans+=word[i];
            }
            else if(word[i]==word[i+1] and count<9){
                count++;
            }
            else{
                ans+=to_string(count);
                count=1;
                ans+=word[i];
            }
        }
        return ans;
    }
};