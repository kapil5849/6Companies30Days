

// 1358. Number of Substrings Containing All Three Characters... 


class Solution {
public:
    int numberOfSubstrings(string s) {
        int left=0,right=0,end=s.size()-1;
        unordered_map<char,int> mpp;
        int cnt=0;
        while(right!=s.size()){
            mpp[s[right]]+=1;
            while(mpp['a'] and mpp['b'] and mpp['c']){
                cnt+=1+(end-right);
                mpp[s[left]]-=1;
                left++;
            }
            right++;
        }
        return cnt;
    }
};
