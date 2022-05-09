class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int>mp;
        
        for(int i=0; i<tasks.size(); i++) {
            mp[tasks[i]]++;
        }
        
        int ans = 0;
        for(int i=0; i<tasks.size(); i++) {
            int val = tasks[i];
            int cnt = mp[val];
            if(cnt == 1) {
                return -1;
            }
            if(cnt%3 == 0) {
                ans = ans + cnt / 3;
            } else if(cnt>0) {
                ans = ans + cnt / 3 + 1;
            }
            mp[val] = 0;
        }
        return ans;
    }
};