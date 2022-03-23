https://www.interviewbit.com/problems/longest-valid-parentheses/

int Solution::longestValidParentheses(string A) {
    stack<int>indices;
    int n=A.size();
    int ans=0, curr;
    indices.push(-1);
    for(int i=0;i<n;i++) {
        if(A[i]==')' && !indices.empty() && (indices.top() != -1 && A[indices.top()]=='(')) {
            indices.pop();
            curr=i-indices.top();
            ans=max(ans, curr);
        } else indices.push(i);
    }
    return ans;
}
