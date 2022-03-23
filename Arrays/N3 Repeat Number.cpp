https://www.interviewbit.com/problems/n3-repeat-number/

int Solution::repeatedNumber(const vector<int> &A) {
    int e1=INT_MAX, e2=INT_MAX;
    int f1=0, f2=0;

    int n=A.size();

    for(int i=0;i<n;i++)
    {
        if(A[i]==e1) ++f1;
        else if(A[i]==e2) ++f2;
        else if(f1==0) {
            f1=1;
            e1=A[i];
        } else if(f2==0) {
            f2=1;
            e2=A[i];
        } else {
            --f1;
            --f2;
        }
    }

    f1=f2=0;
    for(int i=0;i<n;i++) {
        if(A[i]==e1) ++f1;
        else if(A[i]==e2) ++f2;
    }
    if(f1>n/3) return e1;
    if(f2>n/3) return e2;
    return -1;
}
