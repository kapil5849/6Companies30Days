
// 149. Max Points on a Line...

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans=2;
        if(n==1){
            return 1;
        }
        for(int i=0;i<n;i++){
            unordered_map<double,int> mpp;
            for(int j=0;j<n;j++){
                if(j!=i){
                    mpp[atan2(points[j][1]-points[i][1],points[j][0]-points[i][0])]++;
                }
            }
            for(auto [h,temp]:mpp){
                ans=max(ans,temp+1);
            }
        }
        return ans;
    }
};
