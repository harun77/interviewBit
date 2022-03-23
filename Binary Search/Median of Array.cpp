https://www.interviewbit.com/problems/median-of-array/

double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    int m = A.size();
    int n = B.size();
    if(m > n) return findMedianSortedArrays(B, A);

    int L = m+n;
    int midPoint = (L+1)/2;
    int minA, maxA, minB, maxB, cutA, cutB;

    int low = 0, high = m;
    while(low <= high) {
        cutA = (low+high)/2;
        cutB = midPoint-cutA;

        maxA = cutA ? A[cutA-1] : INT_MIN;
        minA = cutA < m ? A[cutA] : INT_MAX;

        maxB = cutB ? B[cutB-1] : INT_MIN;
        minB = cutB < n ? B[cutB] : INT_MAX;

        if(maxA <= minB && maxB <= minA) {
            double median = max(maxA, maxB);
            if(L%2==0) {
                median = (median + min(minA, minB))/2;
            }
            return median;
        } else if(maxA > minB) high=cutA-1;
        else low=cutA+1;
    }
    return 0;
}
