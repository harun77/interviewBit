https://www.interviewbit.com/problems/distinct-subsequences/

int dp[701][701];
string s, t;

int solve(int i, int j) {
    if(j==t.size()) return 1;
    if(i==s.size()) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(s[i] == t[j]) 
        return dp[i][j] = solve(i+1, j+1) + solve(i+1, j);
    return dp[i][j] = solve(i+1, j);
}

int Solution::numDistinct(string A, string B) {
    s = A; t = B;
    memset(dp, -1, sizeof(dp));
    return solve(0, 0);
}
