https://www.interviewbit.com/problems/longest-consecutive-sequence/

int Solution::longestConsecutive(const vector<int> &A) {
    map<int, int>mp;
    int L=A.size();
    int ans=0;
    for(int i=0; i<L; i++) mp[A[i]]=1;
    for(auto &it:mp) {
        it.second += mp[it.first-1];
        ans=max(ans, it.second);
    }
    return ans;
}
