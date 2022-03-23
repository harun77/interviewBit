https://www.interviewbit.com/problems/2-sum/

vector<int> Solution::twoSum(const vector<int> &A, int B) {
    map<int, int>mp;
    int L=A.size();
    for(int i=0;i<L;i++) {
        int need=B-A[i];
        if(mp.find(need) != mp.end()) {
            return {mp[need], i+1};
        }
        if(mp.find(A[i]) == mp.end()) {
            mp[A[i]]=i+1;
        }
    }
    return {};
}
