https://www.interviewbit.com/problems/greatest-common-divisor/

int Solution::gcd(int A, int B) {
    if(!B) return A;
    return gcd(B, A%B);
}
