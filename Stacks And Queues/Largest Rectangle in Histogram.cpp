https://www.interviewbit.com/problems/largest-rectangle-in-histogram/

int Solution::largestRectangleArea(vector<int> &A) {
    stack<int>indexes;
    int n = A.size();
    int maxArea = 0;
    int i = 0;

    while(i<n) {
        if(indexes.empty() || A[indexes.top()]<=A[i]) {
            indexes.push(i);
            ++i;
        } else {
            int top = indexes.top();
            indexes.pop();
            int area = A[top];
            area *= indexes.empty() ? i : i-indexes.top()-1;
            maxArea = max(maxArea, area);
        }
    }
    while(!indexes.empty()) {
        int top = indexes.top();
        indexes.pop();
        int area = A[top];
        area *= indexes.empty() ? n : i-indexes.top()-1;
        maxArea = max(maxArea, area);
    }
    return maxArea;
}
