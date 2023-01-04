

// 581. Shortest Unsorted Continuous Subarray...

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp;
        temp=nums;
        sort(temp.begin(),temp.end());
        int i=0,j=nums.size()-1;
        for(;i<nums.size();i++){
            if(nums[i]!=temp[i]){
                break;
            }
        }
        for(;j>=0;j--){
            if(nums[j]!=temp[j]){
                break;
            }
        }
        int cnt=0;
        for(int k=i;k<=j;k++){
            cnt++;
        }
        return cnt;
    }
};
