class Solution {
public:

    int dist(char a,char b){
        if(a>b)swap(a,b);
        int ans=min(b-a,a-'a'+'z'-b+1);
        return ans;
    }
    string getSmallestString(string s, int k) {
        if(k==0)return s;
        vector <char> alpha;
        for(char i='a';i<='z';i++)alpha.push_back(i);
        string t="";
        for(int i=0;i<s.length();i++){
            int j=(s[i]-97+1)%26;
            int maxi=0;
            if(k==0 or s[i]=='a'){
                t+=s[i];
                continue;
            }
            char flag='z';
            while(alpha[j]!=s[i]){
                int d=dist(s[i],alpha[j]);
                if(d<=k){
                    if(alpha[j]<=flag){
                        maxi=d;
                        flag=alpha[j];
                    }
                }
                j=(j+1)%26;
            }
            k-=maxi;
            t+=flag;
        }
        return t;
    }
};