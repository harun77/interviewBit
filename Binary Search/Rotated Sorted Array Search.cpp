https://www.interviewbit.com/problems/rotated-sorted-array-search/

int Solution::search(const vector<int> &A, int B) {
    int n=A.size();
    int low=0;
    int high=n-1;

    while(low<=high) {
        int mid=(low+high)/2;
        if(A[mid]==B) return mid;
        if(A[low]<=A[mid-1]) {
            if(B>=A[low] && B<=A[mid-1]) high=mid-1; 
            else low=mid+1;
        } else {
            if(B>=A[mid+1] && B<=A[high]) low=mid+1;
            else high=mid-1; 
        }
    }
    return -1;
}