https://www.interviewbit.com/problems/multiply-strings/

string Solution::multiply(string A, string B) {
    int m = A.size();
    int n = B.size();
    vector<int>digits(m+n, 0);

    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());

    int d1, d2, mul;
    for(int i=0;i<n;i++) {
        d1 = B[i]-'0';
        for(int j=0;j<m;j++) {
            d2 = A[j]-'0';
            mul = digits[i+j] + d1*d2;
            digits[i+j] = mul%10;
            digits[i+j+1] += mul/10;
        }
    }
    
    string ret;
    bool taken = false;
    for(int i=digits.size()-1;i>=0;i--)  {
        if(!taken && digits[i]==0) continue;
        ret.push_back(digits[i]+'0');
        taken = true;
    }
    return ret.size() ? ret : "0";
}
