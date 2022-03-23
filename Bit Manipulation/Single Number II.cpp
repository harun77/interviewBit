https://www.interviewbit.com/problems/single-number-ii/

int Solution::singleNumber(const vector<int> &A) {
    int ret=0;
    int n=A.size();
    int one;
    for(int i=0;i<=31;i++) {
        one=0;
        for(int j=0;j<n;j++) {
            if(A[j] & (1<<i)) ++one;
        }
        if(one%3) ret += (1<<i);
    }
    return ret;
}