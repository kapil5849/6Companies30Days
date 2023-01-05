

// 368. Largest Divisible Subset...


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        int maximum=1,num=-1;
        vector<int> v;
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(!(nums[i]%nums[j]) and dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    if(maximum<dp[i]){
                        maximum=dp[i];
                    }
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            if(maximum==dp[i] and (num==-1 or !(num%nums[i]))){
                v.push_back(nums[i]);
                maximum--;
                num=nums[i];
            }
        }
        return v;
    }
};
