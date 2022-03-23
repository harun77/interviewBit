https://www.interviewbit.com/problems/grid-unique-paths/

int Solution::uniquePaths(int A, int B) {
  int ara[A][B];

  for(int i=0;i<A;i++) ara[i][0]=1;
  for(int i=0;i<B;i++) ara[0][i]=1;

  for(int i=1;i<A;i++)
    for(int j=1;j<B;j++)
      ara[i][j] = ara[i-1][j] + ara[i][j-1];

  return ara[A-1][B-1];    
}
