class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        stack<char>stk;
        
        for(int i=0; i<n; ++i){
            if (stk.empty()) {
                stk.push(s[i]);  
            } else if(stk.top() != s[i]) {
                stk.push(s[i]);  
            } else {
                auto prev = stk.top();
                stk.pop();
            }
        }
        
        string ans = "";
        while(!stk.empty()){
            auto cur = stk.top();
            stk.pop();
            ans.push_back(cur);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
