

//  1314. Matrix Block Sum...


class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>> sum(m,vector<int> (n,0)),ans(m,vector<int> (n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                sum[i][j]=mat[i][j];
                if(i-1>=0) sum[i][j]+=sum[i-1][j];
                if(j-1>=0) sum[i][j]+=sum[i][j-1];
                if(i-1>=0 && j-1>=0) sum[i][j]-=sum[i-1][j-1];
            }
        }
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                int temp=0;
                temp+=sum[min(i+k,m-1)][min(j+k,n-1)];
                if(j-k-1>=0) temp-=sum[min(i+k,m-1)][j-k-1];
                if(i-k-1>=0) temp-=sum[max(i-k-1,0)][min(j+k,n-1)];
                if(i-k-1>=0 && j-k-1>=0) temp+=sum[max(i-k-1,0)][max(j-k-1,0)];
                ans[i][j]=temp;
            }
        return ans;
    }
};

