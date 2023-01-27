

//  695. Max Area of Island...

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int mx=0;
        int m=grid.size(); // number of rows...
        int n=grid[0].size(); // number of columns...
        // iterate through the loop,
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int cnt=1; // count 
                // check if value is 1 or not?
                if(grid[i][j]==1){
                    count_island(grid,i,j,cnt);
                    mx=max(mx,cnt);
                }
            }
        }
        return mx;
    }
    int count_island(vector<vector<int>>& grid,int i,int j,int& cnt){
        int m=grid.size(); // number of rows...
        int n=grid[0].size(); // number of columns...
        // base boundary case...
        if(i<0 or i>=m or j<0 or j>=n){
            return 0;
        }
        if(grid[i][j]==0) return 0; // for useless neighbour...
        grid[i][j]=0;
        // check neighbour is helpful or not-> by recursive call... in four direction...
        if(count_island(grid,i-1,j,cnt)) cnt++;
        if(count_island(grid,i+1,j,cnt)) cnt++;
        if(count_island(grid,i,j-1,cnt)) cnt++;
        if(count_island(grid,i,j+1,cnt)) cnt++;
        return 1;
    }
};
