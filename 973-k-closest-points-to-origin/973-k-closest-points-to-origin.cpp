class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        for(auto point: points) {
            cout<<point[0]<<" "<<point[1]<<endl;
            int x = point[0];
            int y = point[1];
            int dis = abs(x*x) + abs(y*y);
            //cout<<"dis "<<dis<<endl;
            pq.push({dis,{x,y}});
        }
        
        vector<vector<int>> ans;
        while(!pq.empty() && k>0) {
            auto front = pq.top();
            pq.pop();
            //cout<<"front "<<front.first<<" "<<front.second.first<<endl;
            ans.push_back({front.second.first,front.second.second});
            k--;
        }
        return ans;
        //reverse(ans.begin(),ans.end());
        //return {ans.begin(), ans.begin() + k};
    }
};