https://www.interviewbit.com/problems/merge-intervals/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

vector<Interval> Solution::insert(vector<Interval> &A, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<Interval>ara, out;
    int L = A.size();
    bool taken = false;
    for(int i=0;i<L;i++)
    {
        Interval curr = A[i];
        if(!taken && newInterval.start <= curr.start) 
        {
            ara.push_back(newInterval);
            taken = true;
        } 
        ara.push_back(curr);
    }
    if(!taken) ara.push_back(newInterval);
    out.push_back(ara[0]);
    for(int i=1;i<=L;i++)
    {
        Interval curr = ara[i];
        int idx = out.size() - 1;
        if(curr.start <= out[idx].end) 
            out[idx].end = max(out[idx].end, curr.end);
        else 
            out.push_back(curr);
    }
    return out;
}
