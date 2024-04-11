class Solution {
public:
    string removeKdigits(string num, int k) {
        stack <char> st;
        for(int i=0;i<num.size();i++){
            while(k>0 and !st.empty() and num[i]<st.top() and i!=0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k>0 and !st.empty()){
            st.pop();
            k--;
        }
        string ans="";
        if(st.empty())return "0";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int flag;
        for(int i=0;i<ans.size();i++){
            if(ans[i]!='0'){
                flag=i-1;
                break;
            }
            else flag=i;
        }
        cout<<ans<<flag;
        ans=ans.substr(flag+1);
        if(ans=="")ans+="0";
        return ans;
        
    }
};