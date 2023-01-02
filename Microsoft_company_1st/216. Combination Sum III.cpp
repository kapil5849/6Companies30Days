

// 216. Combination Sum III...

class Solution {
public:
    void faith(int n,int k,vector<vector<int>> &ans,vector<int> &temp,int index){
        if(n==0 and k==0){
            ans.push_back(temp);
            return;
        }
        if(n==0){
            return;
        }
        for(int i=index;i<=9;i++){
            temp.push_back(i);
            faith(n-i,k-1,ans,temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        faith(n,k,ans,temp,1);
        return ans;
    }
};
