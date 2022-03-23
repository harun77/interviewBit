https://www.interviewbit.com/problems/implement-power-function/

int Solution::pow(int x, int n, int d) {
    long long ret;
    if(n==0) ret = 1%d;
    else if(n==1) ret = x%d;
    else {
        ret = pow(x, n/2, d);
        ret = (ret*ret)%d;
        if(n&1) ret = (x*ret)%d;
    }
    if(ret<0) ret += d;
    return ret;
}
