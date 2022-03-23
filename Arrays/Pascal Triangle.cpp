https://www.interviewbit.com/problems/pascal-triangle/

vector<vector<int> > Solution::solve(int k) {
    vector<vector<int> >pascal;

    if(k>=1) pascal.push_back({1});
    if(k>=2) pascal.push_back({1, 1});

    for(int i=3;i<=k;i++) 
    {
        vector<int>now;
        int L=pascal[i-2].size();
        for(int j=0;j<L;j++)
        {
           if(j==0 || j==L-1) now.push_back(pascal[i-2][j]);
           if(j+1<L) now.push_back(pascal[i-2][j] + pascal[i-2][j+1]);
        }
        pascal.push_back(now);
    }
    return pascal;
}
