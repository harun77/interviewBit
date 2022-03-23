https://www.interviewbit.com/problems/max-distance/

int Solution::maximumGap(const vector<int> &A) {
    vector<pair<int, int>>nums;
    int L=A.size();

    for(int i=0;i<L;i++) nums.push_back({A[i], i});
    sort(nums.begin(), nums.end()); 
    int maxIndex = nums[L-1].second;
    int ans=0;

    for(int i=L-2;i>=0;i--)
    {
        ans=max(ans, maxIndex-nums[i].second);
        maxIndex=max(maxIndex, nums[i].second);
    }
    return ans;
}
