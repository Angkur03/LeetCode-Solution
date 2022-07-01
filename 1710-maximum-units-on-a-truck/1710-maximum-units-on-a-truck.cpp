class Solution {
public:
    static bool cmp(vector<int>first, vector<int>second) {
        return first[1] > second[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(),cmp);
        int res = 0;
        for(int i=0; i<boxTypes.size(); i++) {
            if(truckSize <= 0) {
                break;
            }
            
            int cnt = boxTypes[i][0];
            int value = boxTypes[i][1];
            
            //cout<<cnt<<" "<<boxTypes[i][1]<<endl;
            if(cnt <= truckSize) {
                res = res + cnt * value;
                //cout<<"res "<<res<<endl;
            } else if(truckSize > 0) {
                res = res + truckSize * value;
                //cout<<"res2 "<<res<<endl;
            }
            truckSize-=cnt;
        }
        return res;
    }
};