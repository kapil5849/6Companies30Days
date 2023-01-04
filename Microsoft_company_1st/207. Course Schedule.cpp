

// 207. Course Schedule...


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> topo;
        vector<int> in(numCourses,0);
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            for(auto j:adj[i]){
                in[j]++;
            }
        }
        for(int n=0;n<numCourses;n++){
            if(!in[n]){
                q.push(n);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                in[it]--;
                if(!in[it]){
                    q.push(it);
                }
            }
        }
        return topo.size()==numCourses;
    }
};
