class Solution {
public:
    int kadane(vector<int> vt,int k){
        set<int> st;
        int sum=0;
        int result = INT_MIN;
        st.insert(0);
        for(int i=0;i<vt.size();i++){
            sum+=vt[i];
            auto it=st.lower_bound(sum-k);
            
            if(it!=st.end()){
                result=max(result,sum-(*it));
            }
            
            st.insert(sum);
        }
        
        return result;
    }
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();
        int result=INT_MIN;
        
        for(int l=0;l<m;l++){
            vector<int> sum(n,0);
            for(int r=l;r<m;r++){
                
                for(int i=0;i<n;i++){
                    sum[i]+=matrix[i][r];
                }
                
                result=max(result,kadane(sum,k));
            }
        }
        
        return result;
    }
};