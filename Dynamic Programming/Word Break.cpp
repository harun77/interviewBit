https://www.interviewbit.com/problems/word-break/

int Solution::wordBreak(string A, vector<string> &B) {
    set<string>dict;
    for(auto s:B) dict.insert(s);
    int n = A.size();
    int dp[n+1] = {0};
    dp[n] = 1;
    for(int i=n-1;i>=0;i--) {
        string curr;
        for(int j=i;j<n;j++) {
            curr.push_back(A[j]);
            if(dict.find(curr) != dict.end() && dp[j+1]) {
                dp[i] = 1;
                break;
            }
        }
    }
    return dp[0];
}
