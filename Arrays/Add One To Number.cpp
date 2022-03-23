https://www.interviewbit.com/problems/add-one-to-number/

vector<int> Solution::plusOne(vector<int> &A) {
    int carry = 1;
    int L = A.size();

    for(int i=L-1;i>=0;i--)
    {
        A[i] += carry;
        carry = A[i]/10;
        A[i] %= 10;
    }

    vector<int>out;
    bool taken = false;
    if(carry) 
    {
        out.push_back(carry);
        taken = true;
    }
    for(int i=0;i<L;i++)
    {
        if(!taken && A[i]==0) continue;
        out.push_back(A[i]);
        taken = true;
    }
    return out;
}
