https://www.interviewbit.com/problems/max-rectangle-in-binary-matrix/

int Solution::maximalRectangle(vector<vector<int> > &A) {
    int row = A.size();
    if(!row) return 0;
    int col = A[0].size();

    for(int i=1;i<row;i++) {
        for(int j=0;j<col;j++) {
            if(A[i][j]) A[i][j] += A[i-1][j];
        }
    }

    int maxArea = 0;
    for(int i=0;i<row;i++) {
        stack<int>indexes;
        int k = 0;

        while(k<col) {
            if(indexes.empty() || A[i][indexes.top()] <= A[i][k]) {
                indexes.push(k);
                ++k;
            } else {
                int top = indexes.top();
                indexes.pop();
                int area = A[i][top];
                area *= indexes.empty() ? k : k-indexes.top()-1;
                maxArea = max(maxArea, area);
            }
        }
        while(!indexes.empty()) {
            int top = indexes.top();
            indexes.pop();
            int area = A[i][top];
            area *= indexes.empty() ? k : k-indexes.top()-1;
            maxArea = max(maxArea, area);
        }
    }
    return maxArea;
}
