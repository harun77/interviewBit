https://www.interviewbit.com/problems/disjoint-intervals/

bool comp(vector<int>a, vector<int>b) {
    return a[1] < b[1];
}

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    if(!n) return 0;
    sort(A.begin(), A.end(), comp);
    vector<vector<int> > ans;
    vector<int>pre = A[0];
    ans.push_back(pre);
    for(int i=1;i<n;i++) {
        vector<int>curr = A[i];
        if(curr[0] > pre[1]) {
            ans.push_back(curr);
            pre = curr;
        }
    }
    return ans.size();
}
