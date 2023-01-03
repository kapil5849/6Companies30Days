

// 1976. Number of Ways to Arrive at Destination


#define ll long long
const int mod = 1e9+7;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<roads.size();i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<ll> time(n,LONG_MAX);
        vector<ll> ways(n,0);
        time[0]=0;
        ways[0]=1;
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            ll currTime = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int adjNode = it.first;
                ll timeToTravel = it.second;
                if(currTime+timeToTravel<time[adjNode]){
                    time[adjNode]=currTime+timeToTravel;
                    pq.push({time[adjNode],adjNode});
                    ways[adjNode]=ways[node]%mod;
                }else if(currTime+timeToTravel==time[adjNode]){
                    ways[adjNode]=(ways[adjNode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1];
    }
};
