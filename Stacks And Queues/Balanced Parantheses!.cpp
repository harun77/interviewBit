https://www.interviewbit.com/problems/balanced-parantheses/

int Solution::solve(string A) {
    stack<char>st;
    int n = A.size();
    for(int i=0;i<n;i++) {
        if(A[i]==')' && !st.empty() && st.top()=='(') st.pop();
        else st.push(A[i]);
    }
    return st.empty();
}
