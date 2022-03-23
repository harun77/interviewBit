https://www.interviewbit.com/problems/edit-distance/

string s, t;
vector<vector<int>>dp;

int solve(int i, int j) {
    if(i>=s.size()) return t.size() - j;
    if(j>=t.size()) return s.size() - i;

    if(dp[i][j] != -1) return dp[i][j];

    if(s[i] == t[j]) return dp[i][j] = solve(i+1, j+1);

    int _insert = solve(i, j+1);
    int _delete = solve(i+1, j);
    int _replace = solve(i+1, j+1);

    return dp[i][j] = min(min(_insert, _delete), _replace) + 1;
}

int Solution::minDistance(string A, string B) {
    int x = A.size();
    int y = B.size();
    dp.clear();
    for(int i=0;i<x;i++) dp.push_back(vector<int>(y, -1));
    s = A; t = B;
    return solve(0, 0);
}
