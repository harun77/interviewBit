https://www.interviewbit.com/problems/max-min-05542f2f-69aa-4253-9cc7-84eb7bf739c4/

int Solution::solve(vector<int> &A) {
   int L=A.size();
   if(L==1) return A[0];
   int mx=A[0], mn=A[1];
   if(mx<mn) swap(mx, mn);

   for(int i=2;i<L;i++)
   {
       mx=max(mx, A[i]);
       mn=min(mn, A[i]);
   }
   return mx+mn;
}
