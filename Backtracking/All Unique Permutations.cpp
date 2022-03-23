https://www.interviewbit.com/problems/all-unique-permutations/

set<vector<int>>permutaion;
vector<int>ara;

void solve(int idx, int n) {
    if(idx == n) {
        permutaion.insert(ara);
    }
    for(int i=idx;i<n;i++) {
        swap(ara[idx], ara[i]);
        solve(idx+1, n);
        swap(ara[idx], ara[i]);
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    permutaion.clear();
    ara = A;
    solve(0, A.size());
    vector<vector<int>> ans { permutaion.begin(), permutaion.end() };
    return ans;
}
