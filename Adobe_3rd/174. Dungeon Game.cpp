

// 174. Dungeon Game...

int getVal(vector<vector<int>> &mat, int i=0, int j=0){
        int n = mat.size();
        int m = mat[0].size();
        if(i == n || j == m)    return 1e9; 
        if(i == n-1 and j == m-1)   
            return (mat[i][j] <= 0) ? -mat[i][j] + 1 : 1;
        int IfWeGoRight = getVal(mat , i , j+1);
        int IfWeGoDown = getVal(mat , i+1 , j);
        int minHealthRequired =  min(IfWeGoRight , IfWeGoDown) -mat[i][j];
        return ( minHealthRequired <= 0 ) ? 1 : minHealthRequired;      
}
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        return getVal(dungeon);     
}
