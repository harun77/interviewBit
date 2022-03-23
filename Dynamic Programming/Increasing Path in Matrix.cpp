https://www.interviewbit.com/problems/increasing-path-in-matrix/

int Solution::solve(vector<vector<int> > &A) {
    int n=A.size();
    int m=A[0].size();
    int dp[n][m];
    dp[0][0]=1;

    for(int i=1;i<n;i++) {
        if(dp[i-1][0] != -1 && A[i][0] > A[i-1][0]) {
            dp[i][0] = dp[i-1][0] + 1;
        } else dp[i][0] = -1;
    }
    for(int i=1;i<m;i++) {
        if(dp[0][i-1] != -1 && A[0][i] > A[0][i-1]) {
            dp[0][i] = dp[0][i-1] + 1;
        } else dp[0][i] = -1;
    }

    for(int i=1;i<n;i++) {
        for(int j=1;j<m;j++) {
            int a = A[i][j] > A[i-1][j] ? dp[i-1][j] : -1;
            int b = A[i][j] > A[i][j-1] ? dp[i][j-1] : -1;
            dp[i][j] = max(a, b);
            if(dp[i][j] != -1) ++dp[i][j];
        }
    }
    return dp[n-1][m-1];
}
