class Solution {
public:
    // int solveRec(vector<int>& v,int i,int j){
    //     // base case.....
    //     if(i+1==j) return 0;
    //     int ans=INT_MAX;
    //     for(int k=i+1;k<j;k++){
    //         ans=min(ans,v[i]*v[j]*v[k] + solveRec(v,i,k) + solveRec(v,k,j));
    //     }
    //     return ans;

    // }

    int solveMem(vector<int>& v,vector<vector<int>>& dp,int i,int j){
        if(i+1==j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        for(int k=i+1;k<j;k++){
            ans=min(ans,v[i]*v[j]*v[k] + solveMem(v,dp,i,k) + solveMem(v,dp,k,j));
            // dp[i][j]=ans;
        }
        dp[i][j]=ans;
        return dp[i][j];
    }


    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        // return solveRec(values,0,n-1);
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solveMem(values,dp,0,n-1);
        
    }
};