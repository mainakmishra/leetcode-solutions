class Solution {
public:

    int maxBottlesDrunk(int a, int b) {
        int ans=a;
        while(a>=b){
            ans++;
            a++;
            a-=b;
            b++;
        }
        return ans;
    }
};