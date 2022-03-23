https://www.interviewbit.com/problems/permutations/vector<vector<int>> permutaion;
vector<int>ara;

void solve(int idx, int n) {
    if(idx == n) {
        permutaion.push_back(ara);
        return;
    }
    for(int i=idx;i<n;i++) {
        swap(ara[idx], ara[i]);
        solve(idx+1, n);
        swap(ara[idx], ara[i]); 
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    ara = A;
    permutaion.clear();
    solve(0, A.size());
    return permutaion;
}
