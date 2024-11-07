class Solution {
public:
    // int solveRec(int i,int j,int m,int n){
    //     if(i==m-1 && j==n-1) return 1;
    //     if(i>=m ||j>=n) return 0;
    //     int ans=solveRec(i+1,j,m,n)+solveRec(i,j+1,m,n);
    //     return ans;
    // }

    int solveMem(vector<vector<int>> &dp,int i,int j,int m,int n){
        if(i==m-1 && j==n-1) return 1;
        if(i>=m || j>=n) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        dp[i][j]=solveMem(dp,i+1,j,m,n)+solveMem(dp,i,j+1,m,n);

        return dp[i][j];
    }
    int uniquePaths(int m, int n) {
        // return solveRec(0,0,m,n);
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solveMem(dp,0,0,m,n);
    }
};