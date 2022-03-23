https://www.interviewbit.com/problems/sliding-window-maximum/

vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    deque<pair<int, int>>dq;
    int n = A.size();
    int L = min(n, B);
    for(int i=0;i<L;i++) {
        while(!dq.empty() && dq.front().second <= A[i]) dq.pop_front();
        dq.push_front({i, A[i]});    
    }
    vector<int>ans;
    ans.push_back(dq.back().second);
    for(int i=L;i<n;i++) {
        while(!dq.empty() && dq.front().second <= A[i]) dq.pop_front();
        dq.push_front({i, A[i]});
        if(dq.back().first <= i-B) dq.pop_back();
        ans.push_back(dq.back().second);
    }
    return ans;
}