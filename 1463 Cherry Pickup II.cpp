class Solution {
public:
    int fun(int i, int j1, int j2, int r, int c, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp){
        //base case 
        // if the element goes off from the grid cell 
        if(j1 < 0 || j1 >= c || j2 < 0 || j2 >= c) return -1e8;

        //main function 
        if( i == r-1){
            //if the robot#1 and robot#2 lies on the same cell
            if(j1==j2) return grid[i][j1];
            //if they lies on the different cells of the grid 
            else return grid[i][j1] + grid[i][j2];
        }
        
        //memoization dp
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        //recurrsion
        //explore all paths of robot#1 and robot#2 
        int maxi= -1e8;
        for(int dj1 = -1; dj1 <= +1; dj1++){
            for(int dj2 = -1; dj2 <= +1; dj2++){
                int value = 0;
                if(j1 == j2) value = grid[i][j1];
                else value = grid[i][j1] + grid[i][j2];

                value += fun(i+1, j1+dj1, j2+dj2, r, c, grid, dp);
                maxi= max(maxi, value);
            }
        }
        return dp[i][j1][j2] = maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c,-1)));

        return fun(0, 0, c-1, r, c, grid, dp);
    }
};