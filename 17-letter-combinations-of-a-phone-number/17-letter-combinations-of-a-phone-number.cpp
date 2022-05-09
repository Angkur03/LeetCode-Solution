class Solution {
public:
    vector<string>mapString = { "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string>ans;
    
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) {
            return ans;
        }
        getCombination(digits, 0, digits); 
        //cout<<"ans "<<ans.size()<<endl;
        return ans;
    }
    
    void getCombination(string digits, int index, string pattern) {
        if(index == digits.size()) {
            ans.push_back(pattern);
            return;
        }
        
        int val = digits[index] - '0';
        string mpString = mapString[val];
        for(auto ch: mpString) {
            pattern[index] = ch;
            getCombination(digits,index + 1,pattern); 
        }
    }   
};