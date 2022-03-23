https://www.interviewbit.com/problems/repeating-subsequence/

int dp[101][101];
string s;
int L;

int lcs(int i, int j) {
    if(i>=L || j>=L) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    if(i != j && s[i] == s[j]) 
        return dp[i][j] = 1 + lcs(i+1, j+1);
    return dp[i][j] = max(lcs(i+1, j), lcs(i, j+1));    
}

int Solution::anytwo(string A) {
    s = A;
    L = A.size();
    memset(dp, -1, sizeof(dp));
    return lcs(0, 0) >= 2;
}
