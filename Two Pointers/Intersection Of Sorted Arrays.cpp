https://www.interviewbit.com/problems/intersection-of-sorted-arrays/

vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    int m = A.size();
    int n = B.size();

    int ptr1 = 0, ptr2 = 0;

    vector<int>common;
    while(ptr1<m && ptr2<n) {
        if(A[ptr1] == B[ptr2]) {
            common.push_back(A[ptr1]);
            ++ptr1;
            ++ptr2;
        } else if(A[ptr1] < B[ptr2]) ++ptr1;
        else ++ptr2; 
    }
    return common;
}
