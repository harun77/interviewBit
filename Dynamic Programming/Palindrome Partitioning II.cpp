https://www.interviewbit.com/problems/palindrome-partitioning-ii/

int Solution::minCut(string A) {
    int L = A.size();

    vector<vector<int>>dp(L, vector<int>(L, 0));

    for(int i=L-1;i>=0;i--) {
        for(int j=i+1;j<L;j++) {
            if(j == i+1) dp[i][j] = A[i] != A[j];
            else {
                if(A[i] == A[j] && !dp[i+1][j-1]) dp[i][j] = 0;
                else {
                    dp[i][j] = INT_MAX;

                    for(int k=i;k<=j;k++) {
                        int cut = 1 + dp[i][k];
                        if(k+1<=j) cut += dp[k+1][j];
                        dp[i][j] = min(dp[i][j], cut);
                    }
                }
            }
        }
    }
    return dp[0][L-1];
}
