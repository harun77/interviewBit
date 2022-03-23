https://www.interviewbit.com/problems/max-non-negative-subarray/

vector<int> Solution::maxset(vector<int> &A) {
    int s, e, cS, cE;
    long long sum, _sum;
    int L=A.size();
    s=e=cS=cE=-1;
    sum=0;
    _sum=-1;

    for(int i=0;i<=L;i++)
    {
        if(A[i]<0 || i==L)
        {
            if(cS!=-1)
            {
                if(_sum<sum || (_sum==sum && cE-cS > e-s)) {
                    _sum=sum;
                    s=cS;
                    e=cE;
                }
                cS=cE=-1;
                sum=0;
            }
            continue;
        }
        if(cS==-1)
        {
            sum=A[i];
            cS=i;
        }
        else sum+=A[i];
        cE=i;
    }

    vector<int>out;
    if(s!=-1) for(int i=s;i<=e;i++) out.push_back(A[i]);
    return out;
}
