class Solution {
public:
    int dp[10005] = {-1};
    vector<int>input;
   /* int jump(vector<int>& nums) {
        input = nums;
        for(int i=0; i<nums.size(); i++) {
            dp[i] = -1;
        }
        int ans = jumpGame(0);
        cout<<"main "<<ans<<endl;
        return ans;
    }
    
    int jumpGame(int pos) {
        if (pos == input.size()) {
            return 0;
        }
        //cout<<"called "<<pos<<" "<<cnt<<endl;
        if(dp[pos] != -1) {
            cout<<"pre "<<dp[pos]<<endl;
            return dp[pos];
        }
        //dp[pos] = 1;
        int val = input[pos];
        int sz = input.size();
        int range = pos + val;
        int ans = 100000;
        //cout<<"ans "<<ans<<endl;
        for(int j = pos+1; j<sz && j<=range; j++) {
            if(dp[j] == -1) {
                int ret = 1 + jumpGame(j);
                cout<<ret<<" -- "<<endl;
                ans = min(ans,ret);
                dp[j] = ans;
           }
        }
        return dp[pos] = ans;
    } */
    
    long long int jump(vector<int> &nums , int curr, int dest,vector<int> &dp)
    {       
            if(curr==dest) return 0;
            if(dp[curr]!=-1) return dp[curr];
            //cout<<curr<<" ";
            long long int tmp=INT_MAX;
     
            for(int i=1;i<=nums[curr];i++)
            {   if(i+curr>dest) break;
                tmp=min(tmp,1+jump(nums,curr+i,dest,dp));  
            }
         dp[curr]=tmp;
         return tmp;  
    }
    
    int jump(vector<int>& nums) {
         vector<int> dp(nums.size(),-1);
         return jump(nums,0,nums.size()-1,dp);
    }
};