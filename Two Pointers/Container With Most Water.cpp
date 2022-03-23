https://www.interviewbit.com/problems/container-with-most-water/

int Solution::maxArea(vector<int> &A) {
    int n = A.size();
    int maxArea = 0;

    int ptr1=0, ptr2=n-1;
    int curr;
    while(ptr1<ptr2) {
        curr = min(A[ptr1], A[ptr2])*(ptr2-ptr1);
        if(curr>maxArea) maxArea=curr;
        if(A[ptr1] < A[ptr2]) ++ptr1;
        else if(A[ptr1] > A[ptr2]) --ptr2;
        else {
            ++ptr1;
            --ptr2;
        }
    }
    return maxArea;
}
