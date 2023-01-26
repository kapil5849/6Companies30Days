

// 1823. Find the Winner of the Circular Game...


class Solution {
    public int findTheWinner(int n, int k) {
        int ans=solve(n,k);
        return ans+1;

    }
    public int solve(int n,int k){
        if(n==1) return 0;
        return (solve(n-1,k)+k)%n;
    }
}
