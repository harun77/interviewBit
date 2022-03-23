https://www.interviewbit.com/problems/majority-element/

int Solution::majorityElement(const vector<int> &A) {
    int major, cnt=0;
    for(auto n : A) {
        if(!cnt) major=n;
        cnt += n==major ? 1:-1;
    }
    return major;
}
