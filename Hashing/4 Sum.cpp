https://www.interviewbit.com/problems/4-sum/

vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    map<int, vector<pair<int, int>>>mp;
    int L=A.size();
    for(int i=0;i<L;i++) {
        for(int j=i+1;j<L;j++) {
            mp[A[i]+A[j]].push_back({i, j});
        }
    }
    set<vector<int>>ans;
    for(int i=0;i<L;i++) {
        int a=A[i];
        for(int j=i+1;j<L;j++) {
            int b=A[j];
            int need=B-a-b;
            if(mp.find(need) != mp.end()) {
                for(auto it:mp[need]) {
                    int k=it.first;
                    int l=it.second;
                    if(i!=k && i!=l && j!=k && j!=l) {
                        vector<int>opt;
                        opt.push_back(a);
                        opt.push_back(b);
                        opt.push_back(A[k]);
                        opt.push_back(A[l]);
                        sort(opt.begin(), opt.end());
                        ans.insert(opt);
                    }
                }
            }
        }    
    }
    vector<vector<int>>v{ans.begin(), ans.end()};
    return v;
}
