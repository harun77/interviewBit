https://www.interviewbit.com/problems/sub-matrices-with-sum-zero/

int Solution::solve(vector<vector<int> > &A) {
    int row = A.size();
    if(!row) return 0;
    int col = A[0].size();

    for(int i=0;i<row;i++) 
        for(int j=1;j<col;j++)
            A[i][j] += A[i][j-1];

    int ans = 0;
    for(int left=0; left<col; left++) {
        for(int right=left; right<col; right++) {
            unordered_map<int, int>count;
            count[0] = 1;
            int sum = 0;
            for(int top=0; top<row; top++) {
                sum += A[top][right];
                if(left) sum -= A[top][left-1];
                ans += count[sum];
                ++count[sum];
            }
        }
    }       
    return ans; 
}
