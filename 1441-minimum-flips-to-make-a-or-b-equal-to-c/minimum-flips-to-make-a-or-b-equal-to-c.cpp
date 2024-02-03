class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count=0;
        for(int i=0;i<32;i++){
            int x=(a&(1<<i));
            int y=(b&(1<<i));
            int z=(c&(1<<i));
            if(z==0){
                if(x!=0)++count;
                if(y!=0)++count;
            }
            else{
                if(x==0 and y==0)++count;
            }
        }
        return count;
    }
};