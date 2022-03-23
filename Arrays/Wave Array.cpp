https://www.interviewbit.com/problems/wave-array/

vector<int> Solution::wave(vector<int> &A) {
    sort(A.begin(), A.end());
    int L=A.size();
    for(int i=0;i<L-1;i+=2) swap(A[i], A[i+1]);
    return A;
}
