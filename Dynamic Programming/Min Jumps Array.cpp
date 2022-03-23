https://www.interviewbit.com/problems/min-jumps-array/

int Solution::jump(vector<int> &A) {
    int n = A.size();
    if(n<2) return 0;

    int step = A[0], maxStep = A[0], count = 1;

    for(int i=1;i<n;i++) {
        --step;
        if(step<0) return -1;
        --maxStep;
        maxStep=max(maxStep, A[i]);
        if(i<n-1 && step==0) {
            step = maxStep;
            ++count;
        }
    }
    return count;
}
