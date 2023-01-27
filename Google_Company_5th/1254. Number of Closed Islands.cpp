

// 1254. Number of Closed Islands...

class Solution {
    bool island(vector<vector<int>>& grid,int i,int j){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size())
            return false;
        if(grid[i][j]==1)
            return true;
        grid[i][j]=1;
        bool a=island(grid,i+1,j);
        bool b=island(grid,i-1,j);
        bool c=island(grid,i,j+1);
        bool d=island(grid,i,j-1);
        return a&b&c&d;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size(); // number of rows...
        int n=grid[0].size(); // number of columns...
        int cnt=0; // maintain count...
        // iterate through loop, now...
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // check neighbor is useless or helpful... 
                if(grid[i][j]==0 and island(grid,i,j)==true)
                    cnt++;
            }
        }
        return cnt;
    }
};
