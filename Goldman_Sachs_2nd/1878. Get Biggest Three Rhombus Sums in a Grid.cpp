

// 1878. Get Biggest Three Rhombus Sums in a Grid...

class Solution {
public:
    bool isValid(int row, int col, int numRows, int numCols) {
        return (row >= 0 && row < numRows && col >= 0 && col < numCols);
    }
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        set<int> sums;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                sums.insert(grid[i][j]);
            }
        }
        for(int squareSize=1; squareSize<=50; squareSize++) {
            for(int row=0; row<grid.size(); row++) {
                for(int col=0; col<grid[0].size(); col++) {
                    if(isValid(row-squareSize, col, grid.size(), grid[0].size()) && isValid(row, col-squareSize, grid.size(), grid[0].size()) && isValid(row+squareSize, col, grid.size(), grid[0].size()) && isValid(row, col+squareSize, grid.size(), grid[0].size())) {
                        int sum = grid[row-squareSize][col] + grid[row+squareSize][col] + grid[row][col-squareSize] + grid[row][col+squareSize];
                        for(int diag = 1; diag < squareSize; diag++) {
                            sum += grid[row-diag][col+squareSize-diag];
                        }
                        for(int diag = 1; diag < squareSize; diag++) {
                            sum += grid[row-diag][col-squareSize+diag];
                        }
                        for(int diag = 1; diag < squareSize; diag++) {
                            sum += grid[row+diag][col+squareSize-diag];
                        }
                        for(int diag = 1; diag < squareSize; diag++) {
                            sum += grid[row+diag][col-squareSize+diag];
                        }
                        sums.insert(sum);
                    }
                }
            }
        }
        vector<int> sumsList;
        for(auto it : sums) {
            sumsList.push_back(it);
        }
        reverse(sumsList.begin(), sumsList.end());
        vector<int> topThree;
        if(sumsList.size() < 3) {
            return sumsList;
        }
        for(int i = 0; i < 3; i++) {
            topThree.push_back(sumsList[i]);
        }
        return topThree;
    }
};


