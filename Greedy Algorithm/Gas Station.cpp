https://www.interviewbit.com/problems/gas-station/

int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    int n = A.size();
    int tank, need;
    int totalTank, totalNeed;
    int idx;
     
    tank = need = totalTank = totalNeed = 0;
    
    for(int i=0;i<n;i++) {
        totalTank += A[i];
        totalNeed += B[i];

        if(!tank) idx = i;

        tank += A[i];
        need += B[i];
        if(need>tank) tank = need = 0;
    }
    
    if(totalTank < totalNeed) return -1;
    return idx;
}
