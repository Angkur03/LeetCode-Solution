class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>> >graph(n+5);
        
        for(auto edge: times) {
            int first = edge[0];
            int sec = edge[1];
            int weight = edge[2];
            graph[first].push_back(make_pair(weight,sec));
        }
        
        vector<int>dist(n+5, INT_MAX);
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        pq.push(make_pair(0,k));
        dist[k] = 0;
        
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            //cout<<"top "<<top.second<<" "<<graph[top.second].size()<<endl;
            for(auto child : graph[top.second]) {
                int ar = dist[top.second] + child.first;
                //cout<<ar<<" "<<top.second<<" "<<child.first<<endl;
                if (ar < dist[child.second]) {
                    dist[child.second] = ar;
                    pq.push(make_pair(ar, child.second));
                }
            }
        }
        
        int ans = 0;
        for(int i=1;i<=n;i++){
            ans = max(ans, dist[i]);
            //cout<<i<<" "<<dist[i]<<endl;
        }
        if(ans == INT_MAX) return -1;
        return ans;
        
    }
};