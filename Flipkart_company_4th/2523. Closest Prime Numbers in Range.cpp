

// 2523. Closest Prime Numbers in Range...


vector<int> nums(1000001, 1);
class Solution {
public:
    void findPrimes(){
        nums[1] = 0;
        for(int i = 3; i < 1000; i+=2){
            for(int j = i*i; j < 1000000; j = j + i){
                nums[j] = 0;
            }
        }
    }
    vector<int> closestPrimes(int left, int right) {
        if(nums[2] == 1) findPrimes();
        int ans = -1, diff = INT_MAX, n1 = -1, n2 = -1;
        if(left <= 2) { n2 = 2; left = 3; }
        if(left%2 == 0) left++;
        for(int i = left; i <= right; i+=2){
            if(nums[i]){
                if(n2 == -1) n2 = i;
                else{
                    n1 = n2;
                    n2 = i;
                    if(diff > n2 - n1){
                        diff = n2 - n1;
                        ans = n1; 
                    }
                }
            }
        }
        if( n1 == -1) return {-1, -1};
        return {ans, ans + diff};
    }
};
