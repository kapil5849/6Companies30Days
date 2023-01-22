

// 659. Split Array into Consecutive Subsequences...

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int,int> freq;
        for (int i=0; i<nums.size(); i++){
            freq[nums[i]]++;
        }
        map<int,int> extra;
        for (int i=0; i<nums.size(); i++){
            if (freq[nums[i]]==0)continue;
            freq[nums[i]]--;
            if (extra[nums[i]-1]>0){
                extra[nums[i]-1]--;
                extra[nums[i]]++;
            }
            else if (freq[nums[i]+1]>0 && freq[nums[i]+2]>0){
                freq[nums[i]+1]--;
                freq[nums[i]+2]--;
                extra[nums[i]+2]++;
            }
            else return false;
        }
        return true;
    }
};
