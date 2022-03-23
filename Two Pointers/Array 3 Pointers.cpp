https://www.interviewbit.com/problems/array-3-pointers/

int calculate(int a, int b, int c) {
    int x = abs(a-b);
    int y = abs(b-c);
    int z = abs(c-a);
    return max(x, max(y, z));
}

int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int sA = A.size();
    int sB = B.size();
    int sC = C.size();

    int ptrA, ptrB, ptrC;
    ptrA=ptrB=ptrC=0;
    int ans=INT_MAX, curr;

    while(ptrA<sA && ptrB<sB && ptrC<sC) {
        curr = calculate(A[ptrA], B[ptrB], C[ptrC]);
        if(curr<ans) ans = curr;
        if(A[ptrA] <= B[ptrB] && A[ptrA] <= C[ptrC]) ++ptrA;
        else if(B[ptrB] <= A[ptrA] && B[ptrB] <= C[ptrC]) ++ptrB;
        else ++ptrC;
    }
    return ans;
}
