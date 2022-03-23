https://www.interviewbit.com/problems/merge-overlapping-intervals/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool comp(Interval a, Interval b) {
    return a.start <= b.start;
}

vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<Interval>out;
    int L=A.size();
    if(!L) return out;
    sort(A.begin(), A.end(), comp);
    out.push_back(A[0]);

    for(int i=1;i<L;i++)
    {
        Interval curr=A[i];
        int idx=out.size()-1;
        if(curr.start <= out[idx].end) out[idx].end = max(out[idx].end, curr.end);
        else out.push_back(curr);
    }
    return out;
}
