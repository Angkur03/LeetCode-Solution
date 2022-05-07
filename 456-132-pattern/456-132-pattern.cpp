class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size() - 1;
        int thirdElement = INT_MIN;
        stack<int>st;
        
        for(int i=n; i>=0; i--) {
            int val = nums[i];
            
            if(val < thirdElement) {
                return true;
            }
            
            while(!st.empty() && st.top() < val)  {
                thirdElement = st.top();
            //cout<<st.top()<<endl;
            //st.top();
                st.pop();
            }
            st.push(val);
        }
        //cout<<"sss "<<st.top()<<endl;
        return false;
    }
};