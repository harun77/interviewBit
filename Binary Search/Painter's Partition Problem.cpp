https://www.interviewbit.com/problems/painters-partition-problem/

#define mod 10000003

bool isOk(long long limit, vector<int>list, int painter) {
    int n = list.size();
    int _painter = 1;
    int count = 0;
    for(int i = 0;i < n;i++) {
        if(list[i]>limit) return false;
        if(count+list[i] <= limit) {
            count += list[i];
        } else {
            ++_painter;
            count = list[i];
        }
    }
    return _painter <= painter;
}

int Solution::paint(int A, int B, vector<int> &C) {
    int n = C.size();
    long long total = 0;
    for(int i=0;i<n;i++) total += C[i];

    long long low=0, high=total, mid, ans;
    while(low <= high) {
        mid = (low+high)/2;
        if(isOk(mid, C, A)) {
            ans = mid;
            high = mid-1;
        } else low = mid+1;
    }
    return (ans*B)%mod;
}
