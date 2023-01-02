
// 396. Rotate Function

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long sum=0,temp=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            temp+=nums[i]*i;
        }
        long maxi = temp;
        for(int i=nums.size()-1;i>=0;i--){
            temp+=sum-(nums[i]*nums.size());
            maxi=max(temp,maxi);
        }
        return maxi;
    }
};
