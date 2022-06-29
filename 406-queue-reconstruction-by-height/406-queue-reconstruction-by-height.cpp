class Solution {
public:
    static bool cmp(vector<int>&first, vector<int>&second) {
        if(first[0] == second[0]) {
            return first[1] < second[1];
        }
        return first[0] > second[0];
    }
    
     vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(), cmp);
        int sz = people.size();    
        vector<vector<int>>ans; 
         
        int cnt = 0;
        for(auto person:people) {
            int pos = person[1];
            int val = person[0];
            //cout<<pos<<" "<<val<<endl;
            ans.insert(ans.begin() + pos, person);
        }
        return ans;     
    }
};