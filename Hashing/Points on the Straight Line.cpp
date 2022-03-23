https://www.interviewbit.com/problems/points-on-the-straight-line/

int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    int n=A.size();
    int ans=0;
    for(int i=0;i<n;i++) {
        map<double, int>count;
        int overlapCount=1, otherCount=0;
        for(int j=i+1;j<n;j++) {
            if(A[i]==A[j] && B[i]==B[j]) ++overlapCount;
            else {
                double slope = B[j]==B[i] ? 1e9 : ((double)A[j]-A[i])/(B[j]-B[i]);
                ++count[slope];
                otherCount=max(otherCount, count[slope]);
            }    
        }
        ans = max(ans, otherCount+overlapCount);
    }
    return ans;
}
