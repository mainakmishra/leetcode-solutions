class Solution {
public:
    set<string> st;
    int N;
    void f(string s, int idx){
        if(s.length()==N){
            st.insert(s);
            return;
        }
        for(char i='a';i<='c';i++){
            if(idx){
                if(i!=s[idx-1]){
                    s+=i;
                    f(s,idx+1);
                    s.pop_back();
                }
            }
            else{
                s+=i;
                f(s,idx+1);
                s.pop_back();
            }
        }
        
    }
    string getHappyString(int n, int k) {
        N=n;
        string s="";
        f(s,0);
        vector<string> ans(st.begin(),st.end());
        if(ans.size()<k)return "";
        return ans[k-1];
    }
};