https://www.interviewbit.com/problems/different-bits-sum-pairwise/

#define mod 1000000007

int Solution::cntBits(vector<int> &A) {
    int n=A.size();
    long long ans=0;
    long long one, zero;
    for(int i=0;i<31;i++) {
        one=zero=0;
        for(int j=0;j<n;j++) {
            if(A[j] & (1<<i)) ++one;
            else ++zero;
        }
        ans = (ans + 2*(one*zero)%mod)%mod;
    }
    return (int)ans;
}