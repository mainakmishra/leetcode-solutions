class Solution {
public:
    Solution(){
        ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
    }
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue <int> s1,s2;
        map <int,int> mp1,mp2;
        int count=students.size();
        for(auto &i:students){
            ++mp1[i];
            s1.push(i);
        }
        for(auto &i:sandwiches){
            ++mp2[i];
            s2.push(i);
        }
        while(!s1.empty()){
            if(s1.front()==s2.front()){
                --mp1[s1.front()];
                --mp2[s2.front()];
                s1.pop();
                s2.pop();
                --count;
            }
            else{
                if(mp1[s2.front()]==0)return count;
                s1.push(s1.front());
                s1.pop();
            }
        }
        return count;
    }
};