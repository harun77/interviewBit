https://www.interviewbit.com/problems/longest-common-prefix/

string Solution::longestCommonPrefix(vector<string> &A) {
    string prefix;
    int n = A.size();
    int idx = 0;
    char c;
    bool found = true;
    while(found) {
        for(int i=0;i<n;i++) {
            if(idx < A[i].size() && (!i || A[i][idx] == c)) {
                c = A[i][idx];
            } else { 
                found = false;
                break;
            }
        }
        if(found) {
            prefix.push_back(c);
            ++idx;
        }
    }
    return prefix;
}