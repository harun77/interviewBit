https://www.interviewbit.com/problems/evaluate-expression/

int Solution::evalRPN(vector<string> &A) {
    stack<int>st;
    int n = A.size();
    string s;
    for(int i=0;i<n;i++) {
        s = A[i];
        if(s=="+" || s=="-" || s=="*" || s=="/") {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            if(s=="+") st.push(a+b);
            else if(s=="-") st.push(a-b);
            else if(s=="*") st.push(a*b);
            else st.push(a/b);
        } else {
            st.push(stoi(s));
        }
    }
    return st.top();
}
