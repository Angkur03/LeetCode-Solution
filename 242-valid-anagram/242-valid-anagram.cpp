class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) {
            return false;
        }
        
        map<char,int>mpS;
        
        for(int i=0; i<s.size(); i++) {
            mpS[s[i]]++;
        }
        
        bool flag = true;
        for(int i=0; i<t.size(); i++) {
           if (mpS.find(t[i]) != mpS.end()) {
               mpS[t[i]]--;
           }
        }
        
        for(int i=0; i<s.size(); i++) {
            if (mpS[s[i]] > 0 ){
                cout<<"ss "<<mpS[s[i]]<<endl;
                return false;
            }
            
        }
        
        return true;
    }
};