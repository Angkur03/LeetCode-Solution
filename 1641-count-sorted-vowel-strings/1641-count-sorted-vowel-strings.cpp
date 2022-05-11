class Solution {
public:
    int countVowelStrings(int n) {
        return getCount(n,n,0);
    }
    
    int getCount(int n, int cnt,int pos) {
        if(cnt == 0) {
            return 1;
        }
        if(cnt < 0) {
            return 0;
        }
        
        int ret = 0;
        for(int i=pos; i<5; i++) {
            ret+=getCount(n,cnt-1,i);
        }
        return ret;
    }
};