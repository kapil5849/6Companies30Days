

// 391. Perfect Rectangle...


class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        if(n==1){
            return true;
        }
        map<pair<int,int>,int> mpp;
        for(auto &rect:rectangles){
            mpp[{rect[0],rect[1]}]++;
            mpp[{rect[2],rect[3]}]++;
            mpp[{rect[0],rect[3]}]--;
            mpp[{rect[2],rect[1]}]--;
        }
        int ans=0;
        for(auto it=mpp.begin();it!=mpp.end();it++){
            if(it->second!=0){
                if(abs(it->second)!=1){
                    return false;
                }
                ans++;
            }
        }
        return ans==4;
    }
};
