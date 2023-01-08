
// 593. Valid Square...


class Solution {
public:
    int help(vector<int> & p1,vector<int> & p2){
        return pow((p2[0]-p1[0]),2)+pow(p2[1]-p1[1],2);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int d12=help(p1,p2);
        int d23=help(p2,p3);
        int d34=help(p3,p4);
        int d41=help(p4,p1);
        int d13=help(p1,p3);
        int d24=help(p2,p4);
        unordered_set<int> s;
        s.insert({d12,d23,d34,d41,d13,d24});
        return !s.count(0) and s.size()==2; 
    }
};
