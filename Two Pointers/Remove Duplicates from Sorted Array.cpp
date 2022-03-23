https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array/

int Solution::removeDuplicates(vector<int> &A) {
    int n = A.size();

    int ptr1=0, ptr2=1;

    while(ptr1<n && ptr2<n) {
        if(A[ptr2] == A[ptr1]) ++ptr2;
        else {
            ++ptr1;
            A[ptr1] = A[ptr2];
            ++ptr2;
        }
    }
    return ptr1+1;
}
