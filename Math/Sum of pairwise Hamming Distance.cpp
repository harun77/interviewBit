https://www.interviewbit.com/problems/sum-of-pairwise-hamming-distance/

#define mod 1000000007

int Solution::hammingDistance(const vector<int> &A) {
    long long ret=0;
    long long zero, one;
    int L=A.size();
    for(int i=0;i<31;i++)
    {
        zero=one=0;
        for(int j=0;j<L;j++)
        {
            if(A[j] & (1<<i)) ++one;
            else ++zero;
        }
        ret = (ret + (2*zero*one)%mod)%mod;
    }
    return ret;
}