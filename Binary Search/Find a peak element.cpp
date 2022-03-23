https://www.interviewbit.com/problems/find-a-peak-element/

int Solution::solve(vector<int> &A) {
    int n=A.size();
    int low=0;
    int high=n-1;
    while(low<=high) {
        int mid=(low+high)/2;
        if((mid == 0 || A[mid-1]<=A[mid]) && (mid==n-1 || A[mid+1]<=A[mid]))
            return A[mid];
        if(mid != 0 && A[mid-1]>=A[mid]) high=mid-1;
        else low=mid+1;    
    }
    return -1;
}
