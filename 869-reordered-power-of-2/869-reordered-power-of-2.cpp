class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin(),s.end());
        
        for(int i = 0; i <= 30;i++)
        {
            int x = pow(2,i);
            string s1 = to_string(x);
            sort(s1.begin(),s1.end());
            
            if(s == s1) {
                return true;
            }
        }
        return false;
    }
};
